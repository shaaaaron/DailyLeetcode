/*
 * @lc app=leetcode.cn id=802 lang=cpp
 * @lcpr version=30122
 *
 * [802] 找到最终的安全状态
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
// 拓扑排序不能保证恰好找到所有环的节点
// 逆向拓扑排序
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();

        vector<vector<int>> invG(n);
        for(int i=0;i<n;i++){
            for(auto &j:graph[i]){
                invG[j].push_back(i);
            }
        }

        vector<int> node_in(n);
        for(int i=0;i<n;i++){
            for(auto &j:invG[i]){
                node_in[j]+=1;
            }
        }

        queue<int> q;//记录环
        for(int i=0;i<n;i++){
            if(node_in[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto &j:invG[node]){
                if(node_in[j]){
                    node_in[j]--;
                    if(node_in[j]==0){
                        q.push(j);
                    }
                }
            }
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            if(node_in[i]==0)
                ans.push_back(i);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1],[0]]\n
// @lcpr case=end
// @lcpr case=start
// [[1,2],[2,3],[5],[0],[5],[],[]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3,4],[1,2],[3,4],[0,4],[]]\n
// @lcpr case=end

 */

