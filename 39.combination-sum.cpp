/*
 * @lc app=leetcode.cn id=39 lang=cpp
 * @lcpr version=30122
 *
 * [39] 组合总和
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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> dp(target+5); // 第一维是tar，第二维是不同列表，第三层是列表的不同元素
        // 不用给第二个参数，自动默认构造

        // 完全背包，组合则先物品
        for(auto &can: candidates){
            for(int i=can;i<=target;i++){//索引范围
                if(can == i){
                    dp[i].push_back(vector<int>{can});
                }
                if(can < i){
                    int j=i-can;
                    for(auto tmp_lst : dp[j]){
                        tmp_lst.push_back(can);
                        dp[j+can].push_back(tmp_lst);
                    }
                }
            }
        }
        
        return dp[target];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,6,7]\n7\n
// @lcpr case=end

// @lcpr case=start
// [2,3,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2]\n1\n
// @lcpr case=end

 */

