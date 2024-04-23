/*
 * @lc app=leetcode.cn id=2335 lang=cpp
 * @lcpr version=30122
 *
 * [2335] 装满杯子需要的最短总时长
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
    int fillCups(vector<int>& nums) {
        int ans=0;
        while(true){
            sort(nums.begin(), nums.end(), [](int x, int y){
                return x>y;
            });
            // cout<<nums[0]<<","<<nums[1]<<","<<nums[2]<<endl;

            if(nums[2]==0) {
                ans+=nums[0];
                return ans;
            }

            nums[0]--;
            nums[1]--;
            ans++;
        }   
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,4,2]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,4]\n
// @lcpr case=end

// @lcpr case=start
// [5,0,0]\n
// @lcpr case=end

 */

