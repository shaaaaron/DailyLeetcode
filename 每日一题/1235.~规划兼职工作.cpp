/*
 * @lc app=leetcode.cn id=1235 lang=cpp
 * @lcpr version=30122
 *
 * [1235] 规划兼职工作
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
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<int> idx(n);
        for(int i=0;i<n;i++){
            idx[i]=i;
        }
        sort(idx.begin(), idx.end(), [&](int x,int y){
           return endTime[x]<endTime[y];
        });
        // dp的关键在于，最后一个元素是可以没取到的，不一定非是一定取到。这样放可以二分
        
        vector<int> dp(n);
        for(int i=0;i<n;i++){
            if(i>=1) dp[i]=dp[i-1];
            int lt=0, rt=i-1;
            while(lt<=rt){
                int md=(lt+rt)/2;
                if(endTime[idx[md]]<=startTime[idx[i]]){
                    lt=md+1;
                }else{
                    rt=md-1;
                }
            }
            if(rt>=0)
                dp[i]=max(dp[i], profit[idx[i]]+dp[rt]);
            else
                dp[i]=max(dp[i], profit[idx[i]]);// 不能忘记        
            //cout<<dp[i]<<endl;
        }
        return dp[n-1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,3]\n[3,4,5,6]\n[50,10,40,70]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,6]\n[3,5,10,6,9]\n[20,20,100,70,60]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1]\n[2,3,4]\n[5,6,4]\n
// @lcpr case=end

 */

