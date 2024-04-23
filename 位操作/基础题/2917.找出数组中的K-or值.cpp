/*
 * @lc app=leetcode.cn id=2917 lang=cpp
 * @lcpr version=30122
 *
 * [2917] 找出数组中的K-or值
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
    int findKOr(vector<int>& nums, int k) {
        int ans=0, bit=0; // 表示结果和位数
        int cnt=0; // 表示当前位有几个1
        int quit=0;

        while(true){
            quit=0;
            cnt=0;
            for(int& num:nums){
                if(num&1){
                    cnt++;
                }
                if(num==0){
                    quit++;
                }
                num/=2;
            }

            if(quit==nums.size()){
                break;
            }

            if(cnt>=k){
                ans+=1<<bit;
            }
            bit++;
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [7,12,9,8,9,15]\n4\n
// @lcpr case=end

// @lcpr case=start
// [2,12,1,11,4,5]\n6\n
// @lcpr case=end

// @lcpr case=start
// [10,8,5,9,11,6,8]\n1\n
// @lcpr case=end

 */

