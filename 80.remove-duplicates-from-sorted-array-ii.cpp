/*
 * @lc app=leetcode.cn id=80 lang=cpp
 * @lcpr version=30122
 *
 * [80] 删除有序数组中的重复项 II
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
        int last=nums[0]==INT_MIN; // 注意数据范围，这里不需要特殊处理
        int cnt=0, j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==last && cnt==2){
                continue;
            } 
            nums[j]=nums[i];
            if(nums[i]==last){
                cnt++;
            }else{
                last=nums[i];
                cnt=1;
            }
            j++;
        }
        return j;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1,2,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1,1,1,2,3,3]\n
// @lcpr case=end

 */

