/*
 * @lc app=leetcode.cn id=2642 lang=cpp
 * @lcpr version=30122
 *
 * [2642] 设计可以求最短路径的图类
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
class Graph {
public:
    int n;
    vector<unordered_map<int,int>> memo;

    Graph(int n, vector<vector<int>>& edges) {
        this->n=n;
        memo.resize(n);
        for(auto & eg:edges){
            memo[eg[0]][eg[1]]= eg[2];
        }
    }
    
    void addEdge(vector<int> edge) {
        memo[edge[0]][edge[1]]=edge[2];
    }
    
    int shortestPath(int node1, int node2) {
        vector<int> dis(n, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq; // 小顶堆，默认大顶
        // greater<>不需要指定类型。也不需要自己重写比较函数

        dis[node1]=0;
        pq.emplace(0, node1);
        while(!pq.empty()){
            auto [dx, x]=pq.top();
            pq.pop();
            if(dis[x]<dx) continue;
            for(auto [next, cost]:memo[x]){// pair和tuple都能解引用
                if(dis[next]>dis[x]+cost){
                    dis[next]=dis[x]+cost;
                    pq.emplace(dis[next], next);
                }
            }
        }
        

        return dis[node2]!=INT_MAX? dis[node2]: -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
// @lc code=end



/*
// @lcpr case=start
// ["Graph", "shortestPath", "shortestPath", "addEdge", "shortestPath"][[4, [[0, 2, 5], [0, 1, 2], [1, 2, 1], [3, 0, 3]]], [3, 2], [0, 3], [[1, 3, 4]], [0, 3]]\n
// @lcpr case=end

 */

