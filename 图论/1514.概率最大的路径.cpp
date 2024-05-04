/*
 * @lc app=leetcode.cn id=1514 lang=cpp
 * @lcpr version=30122
 *
 * [1514] 概率最大的路径
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
// dijkstra有向/无向图都可以，
// 本题时贪心最大的。由于dijkstra就是贪心最小的，所以本题依然正确
// Dijkstra算法可以用于有环的图，只要图中所有的边的权重都是非负的
// 无向图
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<unordered_map<int,double>> memo;
        memo.resize(n); // 
        for(int i=0;i<edges.size();i++){
            memo[edges[i][0]][edges[i][1]]=succProb[i];
            memo[edges[i][1]][edges[i][0]]=succProb[i];
        }

        vector<double> dis(n, 0); // 优先选择更大的
        // priority_queue<pair<double,int>, vector<pair<double,int>>, less<>> pq;
        priority_queue<pair<double,int>, vector<pair<double,int>>> pq;
        dis[start_node]=1;
        pq.emplace(1, start_node);
        while(!pq.empty()){
            auto [dx, x]=pq.top();
            pq.pop();
            if(dis[x]>dx) continue;

            for(auto[next, cost]:memo[x]){
                if(dis[x]*cost>dis[next]){
                    dis[next]=dis[x]*cost;
                    pq.emplace(dis[next], next);
                }
            }
        }
        
        return dis[end_node];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n[[1,4],[2,4],[0,4],[0,3],[0,2],[2,3]]\n[0.37,0.17,0.93,0.23,0.39,0.04]\n3\n4\n
// @lcpr case=end
// @lcpr case=start
// 3\n[[0,1],[1,2],[0,2]]\n[0.5,0.5,0.2]\n0\n2\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[0,1],[1,2],[0,2]]\n[0.5,0.5,0.3]\n0\n2\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[0,1]]\n[0.5]\n0\n2\n
// @lcpr case=end

 */

