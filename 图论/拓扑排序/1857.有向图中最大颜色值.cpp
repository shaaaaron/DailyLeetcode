/*
 * @lc app=leetcode.cn id=1857 lang=cpp
 * @lcpr version=30122
 *
 * [1857] 有向图中最大颜色值
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
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        vector<int> in(n);
        vector<set<int>> memo(n);
        for(auto &eg:edges){
            memo[eg[0]].insert(eg[1]);
            in[eg[1]]++;
        }

        vector<vector<int>>  dp(n, vector<int>(26));
        deque<int> dq;
        for(int i=0;i<n;i++){
            if(in[i]==0){
                dq.push_back(i);
                dp[i][colors[i]-'a']=1;
            }
        }

        while(!dq.empty()){
            int cur=dq.front();
            dq.pop_front();
            for(int next:memo[cur]){
                in[next]--;
                for(int i=0;i<26;i++){
                    dp[next][i]=max(dp[next][i], dp[cur][i]+(colors[next]-'a'==i?1:0));
                }
                if(!in[next])
                    dq.push_back(next);
            }
        }

        if(count(in.begin(), in.end(), 0)!=n)
            return -1;

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<26;j++){
                ans=max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abaca"\n[[0,1],[0,2],[2,3],[3,4]]\n
// @lcpr case=end

// @lcpr case=start
// "a"\n[[0,0]]\n
// @lcpr case=end

 */

