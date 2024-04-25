/*
 * @lc app=leetcode.cn id=130 lang=cpp
 * @lcpr version=30122
 *
 * [130] 被围绕的区域
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
    void solve(vector<vector<char>>& board) {
        int m=board.size(), n=board[0].size();
        vector<pair<int,int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};

        vector<vector<int>> vis(m, vector<int>(n));

        function<bool (int,int)> dfs;
        dfs=[&](int x, int y){
            if(x<0||x>=m||y<0||y>=n) return true;
            if(board[x][y]=='X') return false;
            if(vis[x][y]) return false;

            vis[x][y]=1;
            bool flag=false;
            for(auto & pr: dirs){
                flag|=dfs(x+pr.first, y+pr.second);
            }

            return flag;
        };

        function<void (int,int)> op;
        op=[&](int x, int y){
            if(x<0||x>=m||y<0||y>=n) return;
            if(board[x][y]=='X') return;

            board[x][y]='X';
            bool flag=false;
            for(auto & pr: dirs){
                op(x+pr.first, y+pr.second);
            }

            return;
        };

        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='X') continue;
                if(vis[i][j]==false) continue; // 入口的时候还是需要检查，防止出错！
                // 因为true表示没走过，且能走到边界
                //写法很绕，还是用回一开始的写法
                bool flag=dfs(i,j);
                if(flag==false)
                    op(i, j);
            }
        }

        // 做法只需要实现一次dfs，识别出所有边界上的
    }
};
// @lc code=end



/*
// @lcpr case=start
// [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]\n
// @lcpr case=end

// @lcpr case=start
// [["X"]]\n
// @lcpr case=end

 */

