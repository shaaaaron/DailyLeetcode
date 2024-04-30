/*
 * @lc app=leetcode.cn id=26 lang=cpp
 * @lcpr version=30122
 *
 * [26] 删除有序数组中的重复项
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
    int removeDuplicates(vector<int>& nums) {
        int last=nums[0]!=INT_MIN ?nums[0]-1:0; // 可以双指针或者last
        // 需要保证和第一个元素不同
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=last){
                nums[j]=nums[i];
                j++;
            }
            last=nums[i];
        }
        return j;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1,1,2,2,3,3,4]\n
// @lcpr case=end

 */

