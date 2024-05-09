/*
 * @lc app=leetcode.cn id=2054 lang=cpp
 * @lcpr version=30201
 *
 * [2054] 两个最好的不重叠活动
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
    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size();
        
        sort(events.begin(), events.end(), [&](auto& x, auto& y){ // 按结束时间排序
           return  x[1]<y[1];
        });
        
        vector<int> dp(n);
        for(int i=0;i<n;i++){
            if(i==0) dp[i]=events[i][2];
            else dp[i]=max(dp[i-1], events[i][2]); // 对应结束时间能获得的奖励
            // cout<<dp[i]<<endl;
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            int lt=0, rt=n-1; // 搞笑，都没有初始化对
            while(lt<=rt){
                int md=(lt+rt)/2;
                if(events[md][1]<=events[i][0]-1){
                    lt=md+1;
                }else{
                    rt=md-1;
                }
            }
            
            if(rt<=-1) //可以直参加一个活动
                ans=max(ans, events[i][2]);
            else
                ans=max(ans, dp[rt]+events[i][2]);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,3,2],[4,5,2],[2,4,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3,2],[4,5,2],[1,5,5]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,5,3],[1,5,1],[6,6,5]]\n
// @lcpr case=end

 */

