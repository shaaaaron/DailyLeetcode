/*
 * @lc app=leetcode.cn id=1368 lang=cpp
 * @lcpr version=30201
 *
 * [1368] 使网格图至少有一条有效路径的最小代价
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
    int minCost(vector<vector<int>>& grid) {
        vector<pair<int,int>> dirs{{0,1}, {0,-1}, {1,0}, {-1,0}}; // 顺序要和题目一致
        int m=grid.size(), n=grid[0].size();
        int node_num=m*n;
        vector<unordered_map<int,int>> memo(node_num); // 存储0到mn-1中点的索引
        // vector要初始化大小
        for(int x=0;x<m;x++){
            for(int y=0;y<n;y++){
                for(auto [dx, dy]: dirs){
                    if(x+dx<0 || x+dx>=m || y+dy<0 || y+dy>=n){
                        continue;
                    }
                    if( dirs[grid[x][y]-1] == make_pair(dx, dy)){
                        memo[x*n+y][(x+dx)*n+(y+dy)]=0; // 要乘以n不是m
                    }else{
                        memo[x*n+y][(x+dx)*n+(y+dy)]=1;
                    }
                }
            }
        }

        vector<int> dis(node_num, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        dis[0]=0;
        pq.emplace(0,0);

        while(!pq.empty()){
            auto [dis_cur, cur]=pq.top();
            pq.pop();

            if(dis_cur>dis[cur]) continue;
            for(auto [next, cost]:memo[cur]){
                if(dis[cur]+cost<dis[next]){
                    dis[next]=dis[cur]+cost;
                    pq.emplace(dis[next], next);
                }
            }
        }
        // for(int i=0;i<node_num;i++){
        //     cout<<"#"<<i<<": "<<dis[i]<<endl;
        // }
        return dis[node_num-1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,3],[3,2,2],[1,1,4]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[4,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[2,2,2],[2,2,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[4]]\n
// @lcpr case=end

 */

