/*
 * @lc app=leetcode.cn id=797 lang=cpp
 * @lcpr version=30122
 *
 * [797] 所有可能的路径
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
    vector<vector<int>> graph;

    vector<int> vis;// 维护当前路径上访问过的
    vector<int> now;

    vector<vector<int>> ans;
    void bt(int node){// 可以记录当前节点（因为要找到当前节点的边），如果是组合数可以记录下一个开始的节点
        int n=vis.size();
        if(node==n-1){
            ans.push_back(now);
            return;
        }

        for(int next:graph[node]){
            if(vis[next]) continue;
            vis[next]=1;
            now.push_back(next);
            bt(next);
            vis[next]=0;
            now.pop_back();
        }
    }

    // 图中需要考虑的因素
    // - 是否存在自环
    // - 邻接表中的边需要互不相同
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        this->graph=graph;
        vis.resize(graph.size());

        vis[0]=1;
        now.push_back(0);
        bt(0);

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2],[3],[3],[]]\n
// @lcpr case=end

// @lcpr case=start
// [[4,3,1],[3,2,4],[3],[4],[]]\n
// @lcpr case=end

 */

