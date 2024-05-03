/*
 * @lc app=leetcode.cn id=2050 lang=cpp
 * @lcpr version=30122
 *
 * [2050] 并行课程 III
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
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<set<int>> memo(n);
        vector<int> in(n);
        for(auto &re:relations){
            memo[re[0]-1].insert(re[1]-1);
            in[re[1]-1]++;
        }


        deque<int> dq;
        vector<int> dp(n);
        for(int i=0;i<n;i++){
            if(in[i]==0){
                dq.push_back(i);
                dp[i]=time[i];
                // cout<<i<<","<<dp[i]<<endl;
            }
        }

        while(!dq.empty()){
            int cur=dq.front();
            dq.pop_front();
            for(int next:memo[cur]){
                in[next]--;
                dp[next]=max(dp[next], dp[cur]+time[next]);
                if(!in[next]){
                    dq.push_back(next);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n[[1,3],[2,3]]\n[3,2,5]\n
// @lcpr case=end

// @lcpr case=start
// 5\n[[1,5],[2,5],[3,5],[3,4],[4,5]]\n[1,2,3,4,5]\n
// @lcpr case=end

 */

