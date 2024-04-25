/*
 * @lc app=leetcode.cn id=463 lang=cpp
 * @lcpr version=30122
 *
 * [463] 岛屿的周长
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
// 使用双指针，在两个方向上求边的数量
// 或者直接计算，相邻边为水和出界的情况
// 或者计算相邻的陆地情况
    int islandPerimeter(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int ans=0;

        for(int i=0;i<m;i++){
            int start=0, end=0;
            while(start<n){
                if(grid[i][start]==0){
                    start++;
                    continue;
                }

                end=start;
                while(end<n && grid[i][end]==1){
                    end++;
                }
                start=end;
                ans+=2;
            }
        }

        for(int i=0;i<n;i++){
            int start=0, end=0;
            while(start<m){
                if(grid[start][i]==0){
                    start++;
                    continue;
                }

                end=start;
                while(end<m && grid[end][i]==1){
                    end++;
                }
                start=end;
                ans+=2;
            }
        }

        return ans;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0]]\n
// @lcpr case=end

 */

