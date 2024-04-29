/*
 * @lc app=leetcode.cn id=2317 lang=cpp
 * @lcpr version=30122
 *
 * [2317] 操作后的最大异或和
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
    // &只会小不会大，|只会大不会小
    int maximumXOR(vector<int>& nums) {
        vector<int> memo(35);
        for(int num:nums){
            for(int i=0;i<31;i++){
                if(num & 1<<i){
                    memo[i]=1;
                }
            }
        }

        int ans=0;
        for(int i=30;i>=0;i--){
            ans<<=1;
            ans|=memo[i];
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,2,4,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,9,2]\n
// @lcpr case=end

 */

