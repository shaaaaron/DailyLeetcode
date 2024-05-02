/*
 * @lc app=leetcode.cn id=2608 lang=cpp
 * @lcpr version=30122
 *
 * [2608] 图中的最短环
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
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<set<int>> memo(n);   // 可以clear
        for(auto & eg:edges){
            memo[eg[0]].insert(eg[1]);
            memo[eg[1]].insert(eg[0]);
        }

        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            deque<pair<int,int>> dq; // 记录节点的父亲
            vector<int> depth(n, -1);   // 记录深度，也用来判断点是否已经遍历
            
            dq.emplace_back(i,-1);
            depth[i]=0;

            int level=1;
            while(!dq.empty()){
                int dq_size=dq.size();
                for(int i=0;i<dq_size;i++){
                    auto [cur, father] =dq.front();
                    dq.pop_front();
                    for(int next:memo[cur]){
                        if(next==father) continue;
                        if(depth[next]==-1){
                            depth[next]=level;
                            dq.emplace_back(next, cur); //
                        }else{
                            ans=min(ans, depth[next]+depth[cur]+1);
                        }
                            // cout<<cur<<"->"<<next<<":"<<memo[next]<<","<<level<<endl;
                    }
                }
                level++;
            }
        }

        return ans!=INT_MAX?ans:-1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 7\n[[0,1],[1,2],[2,0],[3,4],[4,5],[5,6],[6,3]]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[[0,1],[0,2]]\n
// @lcpr case=end

 */

