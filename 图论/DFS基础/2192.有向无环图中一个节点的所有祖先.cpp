/*
 * @lc app=leetcode.cn id=2192 lang=cpp
 * @lcpr version=30122
 *
 * [2192] 有向无环图中一个节点的所有祖先
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
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> memo(n);

        vector<int> in(n);
        deque<int> dq;
        for(auto & eg:edges){
            in[eg[1]]++;
            memo[eg[0]].push_back(eg[1]);
        }

        for(int i=0;i<n;i++){
            if(in[i]==0)
                dq.push_back(i);
        }

        // 拓扑排序O(V+E)
        vector<set<int>> ans(n);
        while(!dq.empty()){
            int x=dq.front();
            dq.pop_front();
            for(int next:memo[x]){
                // if(in[next]){ // 不需要检查，因为入度保证一定大于等于0
                    in[next]--;
                    ans[next].insert(ans[x].begin(), ans[x].end());
                    ans[next].insert(x);
                    if(in[next]==0){
                        dq.push_back(next);
                    }
                // }
            }
        }

        vector<vector<int>> format_ans(n);
        for(int i=0;i<n;i++){
            format_ans[i].insert(format_ans[i].end(), ans[i].begin(), ans[i].end()); // 指定三个参数
        }
        return format_ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 8\n[[0,3],[0,4],[1,3],[2,4],[2,7],[3,5],[3,6],[3,7],[4,6]]\n
// @lcpr case=end

// @lcpr case=start
// 5\n[[0,1],[0,2],[0,3],[0,4],[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]\n
// @lcpr case=end

 */

