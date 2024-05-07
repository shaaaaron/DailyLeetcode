/*
 * @lc app=leetcode.cn id=741 lang=cpp
 * @lcpr version=30122
 *
 * [741] 摘樱桃
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
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<int>>> f(n * 2 - 1, vector<vector<int>>(n + 1, vector<int>(n + 1, INT_MIN)));
        // 初始化为 intmin
        f[0][1][1] = grid[0][0];
        for (int t = 1; t < n * 2 - 1; t++) {
            for (int j = max(t - n + 1, 0); j <= min(t, n - 1); j++) {
                if (grid[t - j][j] < 0) continue;
                for (int k = j; k <= min(t, n - 1); k++) {
                    if (grid[t - k][k] < 0) continue; // 如果为负数，则仍然是intmin
                    // 否则进行更新。更新完之后可能比intmin大，但是一定是负数
                    f[t][j + 1][k + 1] = max({f[t - 1][j + 1][k + 1], f[t - 1][j + 1][k], f[t - 1][j][k + 1], f[t - 1][j][k]}) +
                                         grid[t - j][j] + (k != j ? grid[t - k][k] : 0);
                }
            }
        }
        return max(f[n * 2 - 2][n][n], 0);
    }

};
// @lc code=end



/*
// @lcpr case=start
// [[1,1,1,1,0,0,0],[0,0,0,1,0,0,0],[0,0,0,1,0,0,1],[1,0,0,1,0,0,0],[0,0,0,1,0,0,0],[0,0,0,1,0,0,0],[0,0,0,1,1,1,1]]\n
// @lcpr case=end
// @lcpr case=start
// [[0,1,-1],[1,0,-1],[1,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,-1],[1,-1,1],[-1,1,1]]\n
// @lcpr case=end

 */

