/*
 * @lc app=leetcode.cn id=137 lang=cpp
 * @lcpr version=30122
 *
 * [137] 只出现一次的数字 II
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
// 中间可能是负数
    int singleNumber(vector<int>& nums) {
        vector<long long> sum(30), cur(30);
        for(long long num:nums){// 中间结果可能越界，需要longlong 
            cur=vector<long long> (30);
            int i=0;
            while(num){
                cur[i]=((num%3)+3)%3;
                num=(num-cur[i])/(-3); // 由于有负数，所以使用-3进制
                i++;
            }
            for(int i=0;i<30;i++){
                sum[i]=(sum[i]+cur[i])%3;
            }
        }

        long long ans=0;
        for(int i=30-1;i>=0;i--){
            ans*=-3;
            ans+=sum[i];
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [43,16,45,89,45,-2147483648,45,2147483646,-2147483647,-2147483648,43,2147483647,-2147483646,-2147483648,89,-2147483646,89,-2147483646,-2147483647,2147483646,-2147483647,16,16,2147483646,43]\n
// @lcpr case=end
// @lcpr case=start
// [2,2,2,-1,-1,-1,8,-7,0,-7,0,-7,0]\n
// @lcpr case=end
// @lcpr case=start
// [2,2,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,0,1,0,1,99]\n
// @lcpr case=end

 */

