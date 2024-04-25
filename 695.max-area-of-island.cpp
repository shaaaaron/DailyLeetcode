/*
 * @lc app=leetcode.cn id=695 lang=cpp
 * @lcpr version=30122
 *
 * [695] 岛屿的最大面积
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
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> vis (m, vector<int>(n));
        vector<pair<int,int>> dirs={{0,1},{0,-1},{1,0},{-1,0}};

        int sum=0;
        function<void(int, int)> dfs; // 提前声明dfs类型，否则auto自动推断会出错。因为使用 auto 类型说明符声明的变量不能出现在其自身的初始值设定项中
        dfs=[&](int x, int y){ // 我感觉，遍历到每个节点时，判断出界/vis/状态维护才更自然
        // 如果遍历到节点，对子节点进行判断，则dfs根节点需要手动设置，而且代码比较繁琐。
            if(x<0||x>=m||y<0||y>=n) return;
            if(grid[x][y]==0 || vis[x][y]) return;

            vis[x][y]=1;
            sum++;
            for(auto & pr : dirs){
                int dx=pr.first, dy=pr.second;
                dfs(x+dx, y+dy);
            }
        };
        
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                sum=0;

                dfs(i,j);
                ans=max(ans, sum);
            }
        }

        return ans;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0,0,0,0,0,0,0]]\n
// @lcpr case=end

 */

