/*
 * @lc app=leetcode.cn id=1997 lang=cpp
 * @lcpr version=30121
 *
 * [1997] 访问完所有房间的第一天
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
    // 注意到0 小于等于 nextVisit[i] 小于等于 i
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        // const int PRIME=int(1e9+7.1); // 检查1e9是int还是浮点数
        // int n=nextVisit.size();
        // TLE，用前缀和优化时间
        // vector<int> dp(n,0);
        // dp[0]=2; // 数组长度至少为2
        // int ans=2;

        // for(int i=1;i<n-1;i++){ // 只需要走到n-2
        //     dp[i]=2;
        //     for(int j=nextVisit[i];j<i;j++){
        //         dp[i]+=dp[j];
        //         dp[i]%=PRIME;
        //     }
        //     ans+=dp[i];
        //     ans%=PRIME;
        //     // cout<<dp[i]<<", ";
        // }

        const int PRIME=int(1e9+7.1); // 检查1e9是int还是浮点数
        int n=nextVisit.size();
        vector<int> dp(n+5,0);
        dp[0]=0; // 数组长度至少为2
        long long ans=0;

        for(int i=0;i<n-1;i++){ // 只需要走到n-2
            dp[i+1]=2;
            // for(int j=nextVisit[i];j<i;j++){
            //     dp[i]+=dp[j];
            //     dp[i]%=PRIME;
            // }
            dp[i+1]=(((long long)dp[i]-dp[nextVisit[i]]+PRIME)+dp[i+1])%PRIME;
            
            ans=(ans+dp[i+1])%PRIME;// 先更新答案再更新前缀和
            dp[i+1]=(dp[i+1]+dp[i])%PRIME;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1]\n
// @lcpr case=end
// @lcpr case=start
// [0,0]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,2,0]\n
// @lcpr case=end

 */

