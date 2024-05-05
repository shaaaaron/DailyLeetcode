using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
class Solution {
public:
    int gcd (int x, int y){
        if(x>y) swap(x,y);
        if(x==0) return y;
        while(x!=0){
            int rem=y%x;
            y=x;
            x=rem;
        }
        return y;
    }
    
    int minAnagramLength(string s) {
        int n=s.size();
        vector<vector<int>> pre(n+1, vector<int>(26));
        for(int i=0;i<n;i++){
            for(int j=0;j<26;j++){
                pre[i+1][j]=pre[i][j]+ (s[i]-'a'==j?1:0);
            }
        }
        
        int max_v=0;
        for(int i=0;i<26;i++){
            max_v=gcd(max_v, pre[n][i]);
        }
        cout<<"max"<<max_v<<endl;
        
        int ans=-1; // 特殊值
        // 由于最小，时间不会超过N
        for(int i=max_v;i>=1;i--){
            // 选择i作为一个周期
            if(n%i) continue; //整除
            int len=n/i; // jia
            
            vector<int> tem(26);
            for(int j=0;j<26;j++){
                tem[j]=pre[len][j]-pre[0][j];
            }
            
            bool succ=true;
            for(int j=0;j<n;j+=len){
                for(int k=0;k<26;k++){
                    if(tem[k]!=pre[j+len][k]-pre[j][k]){
                        succ=false;
                        break;
                    }
                }
                if(!succ) break;
            }
            
            if(succ) return len;
        }
        // if(ans==-1) return n;//6 24 12 6/3/2 4 6
        return ans;
        
    }
};