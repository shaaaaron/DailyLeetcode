/*
 * @lc app=leetcode.cn id=2425 lang=cpp
 * @lcpr version=30122
 *
 * [2425] 所有数对的异或和
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
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(), n=nums2.size();
        int ans=0;
        if(n%2){
            for(int num:nums1){
                ans^=num;
            }
        }
        if(m%2){
            for(int num:nums2){
                ans^=num;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,3]\n[10,2,5,0]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[3,4]\n
// @lcpr case=end

 */

