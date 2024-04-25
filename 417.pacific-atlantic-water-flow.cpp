/*
 * @lc app=leetcode.cn id=417 lang=cpp
 * @lcpr version=30122
 *
 * [417] 太平洋大西洋水流问题
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
public:// 多个点，使用bfs合适
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size(), n=heights[0].size();
        vector<vector<int>> flag(m,vector<int>(n));
        vector<vector<int>> vis(m,vector<int>(n));
        vector<pair<int,int>> dirs{{1,0},{-1,0},{0,1},{0,-1}};

        deque<pair<int,int>> dq;
        for(int i=0;i<m;i++){
            dq.push_back({i,0});
            vis[i][0]=1;
            flag[i][0]|=1;
        }
        for(int i=0;i<n;i++){
            dq.push_back({0,i});
            vis[0][i]=1;
            flag[0][i]|=1;
        }

        while(!dq.empty()){
            int x=dq.front().first, y=dq.front().second; // 不能写错
            dq.pop_front();
            for(int i=0;i<4;i++){
                int dx=dirs[i].first, dy=dirs[i].second;
                if(x+dx<0||x+dx>=m||y+dy<0||y+dy>=n) continue;
                if(heights[x+dx][y+dy]<heights[x][y]) continue;
                if(vis[x+dx][y+dy]) continue;
                
                // cout<<x<<","<<y<<"->"<<x+dx<<","<<y+dy<<endl;
                dq.push_back({x+dx,y+dy});
                vis[x+dx][y+dy]=1;
                flag[x+dx][y+dy]|=1;
            }
        }
        
        vis= vector<vector<int>> (m,vector<int>(n));
        for(int i=0;i<m;i++){
            dq.push_back({i,n-1});
            vis[i][n-1]=1;
            flag[i][n-1]|=2;
        }
        for(int i=0;i<n;i++){
            dq.push_back({m-1,i});
            vis[m-1][i]=1;
            flag[m-1][i]|=2;
        }

        while(!dq.empty()){
            int x=dq.front().first, y=dq.front().second;
            dq.pop_front();
            for(int i=0;i<4;i++){
                int dx=dirs[i].first, dy=dirs[i].second;
                if(x+dx<0||x+dx>=m||y+dy<0||y+dy>=n) continue;
                if(heights[x+dx][y+dy]<heights[x][y]) continue;
                if(vis[x+dx][y+dy]) continue;
                
                dq.push_back({x+dx,y+dy});
                vis[x+dx][y+dy]=1;
                flag[x+dx][y+dy]|=2; // 已经处理，放在队列中知识为了提取儿子
            }
        }

        vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(flag[i][j]==3)
                    ans.push_back(vector<int>{i, j});
            }
        }

        return ans;// 总是忘记
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]\n
// @lcpr case=end

// @lcpr case=start
// [[2,1],[1,2]]\n
// @lcpr case=end

 */

