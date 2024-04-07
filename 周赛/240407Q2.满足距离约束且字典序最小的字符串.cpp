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
    string getSmallestString(string s, int k) {
        int memo[26];
        string ans=s;
        for(int i=0;i<s.size();i++){
            if(k==0) break;
            int j;
            for(j=0;j<26;j++) memo[j]=0;
            
            for(j=0;j<=k;j++){
                memo[(s[i]-'a'+j) % 26]=1; // 初始化
                memo[(s[i]-'a'-j+26*j) % 26]=1; // %%%
            }
            
            for(j=0;j<26;j++){
                if(memo[j]==1) break;
            }
            
            int tmp=s[i]-'a';
            k-= min((j-tmp+26)%26, (tmp-j+26)%26);
            ans[i]='a'+j;
        }
        
        return ans;
    }
};