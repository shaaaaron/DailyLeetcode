/*
 * @lc app=leetcode.cn id=907 lang=cpp
 * @lcpr version=30121
 *
 * [907] 子数组的最小值之和
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
// 两种区间的更新方式
    int sumSubarrayMins(vector<int>& arr) {
        const int PRIME = int(1e9+7.5); // 每一个元素找到右边一个比其（严格）小的元素

        long long ans=0;
        int n=arr.size();
        vector<int> dp(n,0); //一个罕见报错
        stack<int> s; // 存储index
        for(int i=0;i<arr.size();i++){
            while(!s.empty() && arr[s.top()]>arr[i]){
                s.pop();
            }

            if(s.empty()){
                dp[i]=((long long)(i+1)*arr[i])%PRIME;
            }
            else{
                dp[i]=((long long)(i-s.top())*arr[i] + dp[s.top()])%PRIME;
            }
            ans=(ans+ dp[i])%PRIME;
            s.push(i);
        }   

        return (int) ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,1,2,4]\n
// @lcpr case=end

// @lcpr case=start
// [11,81,94,43,3]\n
// @lcpr case=end

 */

