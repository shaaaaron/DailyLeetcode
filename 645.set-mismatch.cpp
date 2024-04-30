/*
 * @lc app=leetcode.cn id=645 lang=cpp
 * @lcpr version=30122
 *
 * [645] 错误的集合
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
// 排序可以O nlogn时间复杂度，但是O n空间复杂度
// 也可以hash table

//  本题无法二分，因为遗漏/重复的最左边和右边无法区分
//  位运算很巧妙，但是很难形容
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int last=-1;
        for(int num:nums){
            if(num==last){
                break;
            }
            last=num;
        }
        // last是重复元素

        int lost=0; // 记录lost元素
        for(int i=1;i<=nums.size();i++){
            lost^=i^nums[i-1];
        }
        lost^=last;
        return {last, lost};
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,2,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,1]\n
// @lcpr case=end

 */

