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
    int numberOfSpecialChars(string word) {
        vector<int> low(50,-1);
        vector<int> up(50,-1);
        for(int i=0;i<word.size();i++){
            if(word[i]>='a' && word[i]<='z'){
                low[word[i]-'a']=i; // 最后一个小c
            }else{
                if(up[word[i]-'A']==-1)// 第一个大c
                    up[word[i]-'A']=i;
            }
        }
        
        int ans=0;
        for(int i=0;i<26;i++){
            if(low[i]!=-1 && up[i]!=-1){
                if(low[i]<up[i])
                    ans++;
            }
        }
        return ans;
        
    
    }
};