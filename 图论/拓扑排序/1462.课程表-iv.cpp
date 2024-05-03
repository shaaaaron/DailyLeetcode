/*
 * @lc app=leetcode.cn id=1462 lang=cpp
 * @lcpr version=30122
 *
 * [1462] 课程表 IV
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
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n=numCourses;
        vector<int> in(n);
        vector<set<int>> memo(n);
        for(auto& eg:prerequisites){
            memo[eg[0]].insert(eg[1]);  
            in[eg[1]]++;
        } 

        deque<int> dq;
        vector<set<int>> lead_node(n); // 记录每个点的先决节点
        for(int i=0;i<n;i++){
            if(in[i]==0){
                dq.push_back(i);
            }
        }

        while(!dq.empty()){
            int cur=dq.front();
            dq.pop_front();
            for(int next:memo[cur]){
                in[next]--;
                lead_node[next].insert(cur);
                lead_node[next].insert(lead_node[cur].begin(), lead_node[cur].end());
                if(in[next]==0){
                    dq.push_back(next);
                }
            }
        }

        vector<bool> ans;
        for(auto &q:queries){
            if(lead_node[q[1]].find(q[0])!=lead_node[q[1]].end())
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n[[1,0]]\n[[0,1],[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[]\n[[1,0],[0,1]]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[1,2],[1,0],[2,0]]\n[[1,0],[1,2]]\n
// @lcpr case=end

 */

