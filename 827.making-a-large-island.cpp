/*
 * @lc app=leetcode.cn id=827 lang=cpp
 * @lcpr version=30122
 *
 * [827] 最大人工岛
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
    int m, n;
    vector<vector<int>> grid;
    vector<vector<int>> vis;
    
    vector<pair<int,int>> dirs{{1,0},{-1,0},{0,1},{0,-1}};

    int sum=0;


    unordered_map<int, int> memo;
    void dfs(int x, int y, int start){
        if(x<0||x>=m||y<0||y>=n) return;
        if(grid[x][y]==0) return;
        if(vis[x][y]!=-1) return;
        vis[x][y]=start;
        sum++;
        for(int i=0;i<4;i++){
            int dx=dirs[i].first, dy=dirs[i].second;
            dfs(x+dx, y+dy, start);
        }
    }

    tuple<int,int> get_num(int x, int y){
        if(x<0||x>=m||y<0||y>=n) return {-1, 0};
        return {vis[x][y], memo[vis[x][y]]};//
    }

    int largestIsland(vector<vector<int>>& grid) {
        this->grid=grid; //！重要，否则会导致undefined 行为
        m=grid.size(), n=grid[0].size();
        vis = vector<vector<int>> (m, vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // 遍历岛屿1
                if(grid[i][j]==0) continue;
                if(vis[i][j]!=-1) continue;

                sum=0;
                dfs(i,j,i*n+j);
                memo[i*n+j]=sum;
            }
        }
        
        int ans=0;
        bool flag=false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) continue;

                flag=true;
                unordered_map<int,int> tmp;
                for(int step=0;step<4;step++){ // step和i不能用混！
                    int dx=dirs[step].first, dy=dirs[step].second;
                    auto [node, num]=get_num(i+dx, j+dy);
                    tmp[node]=num;
                }

                int now=0;
                for(auto &pr:tmp){
                    now+=pr.second;
                }
                ans=max(ans, now+1);
            }
        }

        if(flag==false) return m*n; // 考虑到没有0的情况，此时必然全部联通
        return ans;// 否则一定是变0为1的结果最大
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1, 0], [0, 1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1, 1], [1, 0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1, 1], [1, 1]]\n
// @lcpr case=end

 */

