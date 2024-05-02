/*
 * @lc app=leetcode.cn id=2039 lang=cpp
 * @lcpr version=30122
 *
 * [2039] 网络空闲的时刻
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <set>
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
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n=patience.size();
        vector<set<int>> memo(n);
        for(auto& eg:edges){
            memo[eg[0]].insert(eg[1]);
            memo[eg[1]].insert(eg[0]);
        }

        vector<int> depth(n,-1);
        depth[0]=0;
        deque<int> dq;
        dq.push_back(0);
        while(!dq.empty()){
            int cur=dq.front();
            dq.pop_front();
            for(int next:memo[cur]){
                if(depth[next]!=-1) continue;
                depth[next]=depth[cur]+1;
                dq.push_back(next);
            }
        }

        int ans=0;
        for(int i=1;i<n;i++){
            // cout<<2*depth[i]<<","<<patience[i]<<endl;
            ans=max(ans, (2*depth[i]-1)/patience[i]*patience[i]+2*depth[i]);
        }

        return ans+1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,1],[1,2]]\n[0,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1],[0,2],[1,2]]\n[0,10,10]\n
// @lcpr case=end

 */

