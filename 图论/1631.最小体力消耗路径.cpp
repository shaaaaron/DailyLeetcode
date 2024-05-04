/*
 * @lc app=leetcode.cn id=1631 lang=cpp
 * @lcpr version=30122
 *
 * [1631] 最小体力消耗路径
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

// 无权图上，bfs就相当于dijkstra
// 本题无法dp，因为四个方向，但是dijkstra，
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size(), n=heights[0].size();
        vector<vector<int>> dis(m, vector<int>(n, INT_MAX));

        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> pq;
        dis[0][0]=0;
        pq.emplace(0, make_pair(0,0)); // 没有问题，多个pair可以并列写参数
        // 如果emplace(0,0,0)会编译错误
        vector<pair<int,int>> dirs={{0,1},{0,-1},{1,0},{-1,0}};
        while(!pq.empty()){
            auto [dis_cur, cur]=pq.top();
            auto [x, y]=cur;
            pq.pop();
            if(dis[x][y]<dis_cur) continue;

            for(auto [dx, dy]:dirs){
                if(x+dx<0 || x+dx>=m || y+dy<0 || y+dy>=n) continue;
                if(dis[x+dx][y+dy]> max(dis[x][y], abs(heights[x][y]-heights[x+dx][y+dy]))){
                    dis[x+dx][y+dy]=max(dis[x][y], abs(heights[x][y]-heights[x+dx][y+dy]));
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
// [[1,2,2],[3,8,2],[5,3,5]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[3,8,4],[5,3,5]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]\n
// @lcpr case=end

 */

