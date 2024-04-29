/*
 * @lc app=leetcode.cn id=2639 lang=cpp
 * @lcpr version=30122
 *
 * [2639] 查询网格图中每一列的宽度
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
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int> ans;
        int m=grid.size(), n=grid[0].size();

        for(int j=0;j<n;j++){
            int max_val=0;
            for(int i=0;i<m;i++){
                max_val=max(max_val, (int)to_string(grid[i][j]).size()); // 显示转化

                // 直接转化为str计算大小
            }
            ans.push_back(max_val);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,-1,-200,99]]\n
// @lcpr case=end
// @lcpr case=start
// [[1],[22],[333]]\n
// @lcpr case=end

// @lcpr case=start
// [[-15,1,3],[15,7,12],[5,6,-2]]\n
// @lcpr case=end

 */

