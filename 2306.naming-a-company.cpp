/*
 * @lc app=leetcode.cn id=2306 lang=cpp
 * @lcpr version=30202
 *
 * [2306] 公司命名
 */


// @lcpr-template-start
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
#include <set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start

class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        vector<unordered_set<string>> memo(26);
        for(string word:ideas){
            int ch=word[0]-'a';
            memo[ch].insert(word.substr(1));
        }
        cout<<memo[0].size()<<"," <<memo[1].size()<<endl;
        vector<unordered_set<string>> memo2(26*26);
        for(int i=0;i<26;i++){
            for(int j=i+1;j<26;j++){
                for(string word:memo[i]){
                    if(memo[j].find(word)!=memo[j].end()){
                        memo2[i*26+j].insert(word);
                    }
                }
                for(string word:memo[j]){
                    if(memo[i].find(word)!=memo[i].end()){
                        memo2[i*26+j].insert(word);
                    }
                }
                // set_intersection(memo[i].begin(), memo[i].end(), memo[j].begin(), memo[j].end(), inserter(memo2[i*26+j], memo2[i*26+j].begin()));
            }
        }
        cout<<memo2[0*26+1].size()<<endl;

        long long ans=0;
        for(string word:ideas){
            int i=word[0]-'a';
            for(int j=0;j<26;j++){
                if(i==j) continue;
                if( memo[j].find(word.substr(1))!=memo[j].end()){
                    continue;
                }
                int new_i=i, new_j=j;
                if(new_i>new_j) swap(new_i, new_j);
                ans+=memo[j].size()-memo2[new_i*26+new_j].size();
                // 对于所有可交换的，还要减去其中重复存在的
            }
            // cout<<word<<","<<ans<<endl;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["aaa", "baa", "bbb", "cbb"]\n
// @lcpr case=end
// @lcpr case=start
// ["coffee","donuts","time","toffee"]\n
// @lcpr case=end

// @lcpr case=start
// ["lack","back"]\n
// @lcpr case=end

 */

