/*
 * @lc app=leetcode.cn id=2577 lang=cpp
 * @lcpr version=30122
 *
 * [2577] 在网格图中访问一个格子的最少时间
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
// 1、从图中抽象出更少的节点，如2662。否则本题直接搜，20个节点以上就超时
// 2、到达目标之前/之后需要等待，如2045
// 3、只要有一个空位，则可以腾挪等待，而不需要任何记录
// 4、本题不需要奇偶节点，但是要考虑到
    int minimumTime(vector<vector<int>>& grid) {
       int m=grid.size(), n=grid[0].size();
       if(grid[1][0]>=2 && grid[0][1]>=2) return -1; 
       // 其他情况下则都可以

        // for(int i=0;i<n;i++){ // 难绷
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // if(i==0 && j==0) continue; // 注意第一个// 没问题
                if((i+j)%2==0 && grid[i][j]%2){
                    grid[i][j]++;
                }
                if((i+j)%2 && grid[i][j]%2==0){
                    grid[i][j]++;
                }
            }
        }

        vector<vector<int>> dis(m, vector<int>(n, INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> pq;// 第二个是二维坐标，但是不是下标
        dis[0][0]=0;
        // pq.emplace(0,0,0); // 编译错误
        // pq.emplace(0, {0,0}); // 编译错误
        pq.emplace(0, make_pair(0,0));
        
        vector<pair<int,int>> dirs={{0,1},{0,-1},{1,0},{-1,0}};
        while(!pq.empty()){
            auto [dis_cur, cur]=pq.top();
            auto [x, y]=cur;
            pq.pop(); // 难绷
            // cout<<x<<","<<y<<":"<<dis_cur<<endl;
            if(dis_cur>dis[x][y]) continue;
            for(auto [dx, dy]:dirs){
                if(x+dx<0 || x+dx>=m || y+dy<0 || y+dy>=n) continue;
                int new_dis=dis[x][y]+max(1, grid[x+dx][y+dy]-dis[x][y]);
                if(new_dis< dis[x+dx][y+dy]){
                    dis[x+dx][y+dy]=new_dis;
                    // pq.emplace(dis[x+dx][y+dy], make_pair(x+dx, y+dy));
                    pq.emplace(dis[x+dx][y+dy], make_pair(x+dx, y+dy));
                }
            }
        }

        return dis[m-1][n-1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,1,3,2],[5,1,2,5],[4,3,8,6]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,2,4],[3,2,1],[1,0,4]]\n
// @lcpr case=end

 */

