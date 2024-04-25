/*
 * @lc app=leetcode.cn id=1020 lang=cpp
 * @lcpr version=30122
 *
 * [1020] 飞地的数量
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
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<pair<int,int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};

        vector<vector<int>> vis(m, vector<int>(n));

        int sum;

        function<bool (int,int)> dfs;
        dfs=[&](int x, int y){
            if(x<0||x>=m||y<0||y>=n) return true;
            if(vis[x][y]) return false;
            if(grid[x][y]==0) return false;

            vis[x][y]=1;
            sum++;
            bool flag=false;
            for(auto & pr: dirs){
                flag|=dfs(x+pr.first, y+pr.second);
            }

            return flag;
        };

        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                sum=0;
                bool flag=dfs(i,j);
                if(flag==false)
                    ans+=sum; // 傻逼了，记得看题
            }
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]\n
// @lcpr case=end

 */

// [
// [0,0,0,1,1,1,0,1,0,0],
// [1,1,0,0,0,1,0,1,1,1],
// [0,0,0,1,1,1,0,1,0,0],
// [0,1,1,0,0,0,*,0,*,0],
// [0,1,1,1,1,1,0,0,*,0],
// [0,0,1,0,1,1,1,1,0,1],
// [0,1,1,0,0,0,1,1,1,1],
// [0,0,1,0,0,1,0,1,0,1],
// [1,0,1,0,1,1,0,0,0,0],
// [0,0,0,0,1,1,0,0,0,1]]
