/*
 * @lc app=leetcode.cn id=139 lang=cpp
 * @lcpr version=30121
 *
 * [139] 单词拆分
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
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
// 看看记忆化搜索怎么做
    bool wordBreak(string s, vector<string>& wordDict) {
        // 重要的是想清楚状态怎么表示，前i个能不能表示，太天才了
        int n=s.size();
        vector<int> dp(n+1, 0); // 0 第一个元素  ... 第n个元素
        // 一定要比实际长
        dp[0]=1;
        for(int i=1;i<=n; i++){ //第i个字符（包含）之前的字符串
            for(auto & word: wordDict){
                if(word.size()<=i && word == s.substr(i-word.size()+1 -1, word.size())){ // 遇到s要-1，否则表示第n个字符
                    dp[i]=max(dp[i], dp[i-word.size()]);
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "leetcode"\n["leet", "code"]\n
// @lcpr case=end

// @lcpr case=start
// "applepenapple"\n["apple", "pen"]\n
// @lcpr case=end

// @lcpr case=start
// "catsandog"\n["cats", "dog", "sand", "and", "cat"]\n
// @lcpr case=end

 */

