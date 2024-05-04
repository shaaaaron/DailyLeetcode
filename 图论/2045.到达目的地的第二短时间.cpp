/*
 * @lc app=leetcode.cn id=2045 lang=cpp
 * @lcpr version=30122
 *
 * [2045] 到达目的地的第二短时间
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
// 题目中要求严格数值第二小（如果数值相同忽略不计），则可以在dijkstra基础上，维护最小和严格数值第二小
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        // 节点是1到n，在memo初始化时直接转化为0到n-1
        unordered_map<int,unordered_map<int,int>> memo;
        for(auto & eg: edges){
            memo[eg[0]-1][eg[1]-1]=time; // 停离谱的，压根不是带权图，边权固定
            memo[eg[1]-1][eg[0]-1]=time;
        }

        // 注意题目是无向图，并且允许往返，见case2
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        vector<int> dis1(n,INT_MAX), dis2(n,INT_MAX);
        dis1[0]=0;
        pq.emplace(0, 0);

        // dijkstra但是每个节点相当于两次，两次都好了才推出
        while(pq.size()){ // 要加这个，只有下面的会出错。pq在空了之后仍然可以正常pop，但是size会巨大
            auto [dis_cur, cur]=pq.top();// 队列中存储的时间是到达时间
            // cout<<cur<<",size:"<<pq.size()<<endl;;
            pq.pop();
            // if(dis_cur>dis2[n-1]){// 之后不会找到更小的
            //     break; // break之后统一return，统一代码出口，防止出错
            // } // 其实不需要这个

            if(dis_cur >dis2[cur]){// 小的已经遍历过了
                continue;
            }

            // 将到达时间转化为出发时间
            if(dis_cur%(change*2)>=change){
                dis_cur=dis_cur-dis_cur%(2*change)+2*change;
            }
            for(auto [next, cost]: memo[cur]){
                if(cost==INT_MAX) continue; // 放置越界
                if(dis_cur+cost == dis1[next] || dis_cur+cost == dis2[next] ) continue;
                if(dis_cur+cost > dis2[next]) continue;
                if(dis_cur+cost<dis1[next]){
                    dis2[next]=dis1[next];
                    dis1[next]=dis_cur+cost;
                }else if(dis_cur+cost<dis2[next]){
                    dis2[next]=dis_cur+cost;
                }
                pq.emplace(dis_cur+cost, next);  
                // cout<<   dis_cur+cost<<","<< next<<endl;
            }

        }
        return dis2[n-1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n[[1,2],[1,3],[1,4],[3,4],[4,5]]\n3\n5\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[1,2]]\n3\n2\n
// @lcpr case=end

 */

