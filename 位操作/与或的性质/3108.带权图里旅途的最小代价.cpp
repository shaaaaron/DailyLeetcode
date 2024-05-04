/*
 * @lc app=leetcode.cn id=3108 lang=cpp
 * @lcpr version=30122
 *
 * [3108] 带权图里旅途的最小代价
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
// 无向图允许往返走，则之和所在连通分支有关。因为边越多越好
    vector<int> p;
    int find(int x){
        if(x==p[x]) return x;
        return p[x]=find(p[x]);
    }

    void merge(int x,int y){
        p[find(x)]=find(y);
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        p.resize(n);
        for(int i=0;i<n;i++){
            p[i]=i;
        }
        for(auto&eg:edges){
            merge(eg[0], eg[1]);
        }
        
        vector<int> cost(n, INT_MAX);
        for(int i=0;i<n;i++){
            find(i); // 规整一下
        }
        for(auto&eg:edges){
            cost[p[eg[0]]]&=eg[2];
        }
        
        vector<int> ans;
        for(auto q:query){
            if(p[q[0]]!=p[q[1]])
                ans.push_back(-1);
            else // 保证起点和终点不同，否则需要特判
                ans.push_back(cost[p[q[0]]]);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n[[0,1,7],[1,3,7],[1,2,1]]\n[[0,3],[3,4]]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[0,2,7],[0,1,15],[1,2,6],[1,2,1]]\n[[1,2]]\n
// @lcpr case=end

 */

