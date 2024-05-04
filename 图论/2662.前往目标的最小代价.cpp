/*
 * @lc app=leetcode.cn id=2662 lang=cpp
 * @lcpr version=30122
 *
 * [2662] 前往目标的最小代价
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
#include <set>
#include <cassert>
// @lcpr-template-end
// @lc code=start

//https://www.cainiaojc.com/cpp/cpp-set-find-function.html
//https://blog.csdn.net/o0onlylove0o/article/details/131341440
// 只需要关键节点
// 其他节点满足距离的三角不等式，一定是直接走到开销更小
class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        set<pair<int,int>> node_set;
        node_set.emplace(start[0], start[1]);
        node_set.emplace(target[0], target[1]);
        for(auto & vec:specialRoads){
            node_set.emplace(vec[0], vec[1]);   
            node_set.emplace(vec[2], vec[3]);
        }

        int n=node_set.size();
        vector<vector<int>> memo(n, vector<int>(n, INT_MAX));
        // node_set中的点对应0到n-1，但不是按顺序
        //https://blog.csdn.net/wusecaiyun/article/details/49563197

        // for loop 初始化不支持同时int和auto，也不支持两个auto不同的
        vector<pair<int,int>> node(node_set.begin(), node_set.end()); // 还是要一个，不然后面迭代器不支持随机访问太痛苦了

        for(int i=0;i<n;i++){
            assert(i==distance(node_set.begin(), node_set.find(node[i])));
        }

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                auto [xi, yi]=*(node.begin()+i);
                auto [xj, yj]=*(node.begin()+j);
                memo[i][j]=memo[j][i]=abs(xi-xj)+abs(yi-yj);
            }
        }

        // distance(node_set.begin(), node_set.end()); // 但是支持distance
        for(auto & vec:specialRoads){
            int i=distance(node_set.begin(), node_set.find({vec[0], vec[1]}));
            int j=distance(node_set.begin(), node_set.find({vec[2], vec[3]}));
            memo[i][j]=min(memo[i][j], vec[4]);
        }

        int start_idx=distance(node_set.begin(), node_set.find({start[0], start[1]})); // set才能find
        int end_idx=distance(node_set.begin(), node_set.find({target[0], target[1]}));

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        vector<int> dis(n, INT_MAX); // 初始化最大
        dis[start_idx]=0;
        pq.emplace(0, start_idx);

        while(!pq.empty()){
            auto [cur_dis, cur]=pq.top();
            pq.pop();

            if(dis[cur]<cur_dis) continue;
            for(int next=0;next<n;next++){
                // if(next==cur) continue; // 自己到自己时max
                // 其实有零边也可以处理
                if(memo[cur][next]!=INT_MAX && dis[next] > dis[cur]+memo[cur][next]){ // 1
                    dis[next]=dis[cur]+memo[cur][next];
                    pq.emplace(dis[next], next);
                }
            }
        }
        
        return dis[end_idx];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1]\n[4,5]\n[[1,2,3,3,2],[3,4,4,5,1]]\n
// @lcpr case=end

// @lcpr case=start
// [3,2]\n[5,7]\n[[3,2,3,4,4],[3,3,5,5,5],[3,4,5,6,6]]\n
// @lcpr case=end

 */

