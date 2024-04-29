/*
 * @lc app=leetcode.cn id=1250 lang=cpp
 * @lcpr version=30122
 *
 * [1250] 检查「好数组」
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
    int change(int x, int y){ // 都为 正数
        if(x>y) swap(x, y);
        // cout<<x<<","<<y<<endl;

        while(x!=0){
            int tmp=y%x;
            y=x;
            x=tmp;
        }
        return y;
    }
    
    bool isGoodArray(vector<int>& nums) {
        if(nums.size()==1) return nums[0]==1 ? true : false;

        int ans=nums[0];
        for(int i=1;i<nums.size();i++){ // 默认数组长度大于等于2
            ans=change(ans, nums[i]);
            if(ans==1) return true;
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [12,5,7,23]\n
// @lcpr case=end

// @lcpr case=start
// [29,6,10]\n
// @lcpr case=end

// @lcpr case=start
// [3,6]\n
// @lcpr case=end

 */

