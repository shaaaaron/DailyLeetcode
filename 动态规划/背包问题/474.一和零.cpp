/*
 * @lc app=leetcode.cn id=474 lang=cpp
 * @lcpr version=30121
 *
 * [474] 一和零
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
    //01背包，容量限制 
    tuple<int,int> count_str(string& s){
        int count0=0;
        for(auto ch: s){
            if(ch=='0')count0++;
        }
        return {count0, s.size()-count0};
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0)); // 默认为0

        for(auto& str: strs){
            auto [count0, count1] = count_str(str); // 注意使用方法
            for(int i=m; i>=count0; i--){ // 直接扩展到多维
                for(int j=n; j>=count1; j--){
                    dp[i][j]=max(dp[i][j], dp[i-count0][j-count1]+1);
                }
            }
        }
        int ans=0;
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                ans=max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["10", "0001", "111001", "1", "0"]\n5\n3\n
// @lcpr case=end

// @lcpr case=start
// ["10", "0", "1"]\n1\n1\n
// @lcpr case=end

 */

