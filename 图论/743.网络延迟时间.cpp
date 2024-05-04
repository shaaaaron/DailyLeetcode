/*
 * @lc app=leetcode.cn id=743 lang=cpp
 * @lcpr version=30122
 *
 * [743] 网络延迟时间
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
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<unordered_map<int, int>> adj(n + 1); // 外层应该是vector，不要用map。内层用mpa
        for (const auto& time : times) {
            int u = time[0], v = time[1], w = time[2];
            adj[u][v] = w;
        }

        // 只要给函数里面给参数，外面可以auto
        auto comp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        };// 使用 > 来保证最小的元素在优先队列的顶部

        // 这里完全不用函数参数的显示声明
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);// 存储起点到对应点的距离
        // decltype自动推断

        vector<int> distance(n + 1, INT_MAX);
        vector<bool> visited(n + 1, false);

        distance[k] = 0;
        pq.push({k, 0});

        while (!pq.empty()) {
            auto [node, dist] = pq.top(); // 自动解绑定
            pq.pop();

            if (visited[node]) continue;
            visited[node] = true;

            for (const auto& [next, weight] : adj[node]) { // distance存储目前的最小距离
                if (distance[node] + weight < distance[next]) { // 只有比当前小才更新
                    distance[next] = distance[node] + weight;
                    pq.push({next, distance[next]});
                }
            }
        }

        int result = 0;
        for (int i = 1; i <= n; ++i) {
            if (distance[i] == INT_MAX) return -1;
            result = max(result, distance[i]);
        }

        return result;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[2,1,1],[2,3,1],[3,4,1]]\n4\n2\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,1]]\n2\n1\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,1]]\n2\n2\n
// @lcpr case=end

 */

