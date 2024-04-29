/*
 * @lc app=leetcode.cn id=1835 lang=cpp
 * @lcpr version=30122
 *
 * [1835] 所有数对按位与结果的异或和
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
 // 对单位总结规律，推广到多位。只要不进位都可以总结
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int res=0;
        for(int num:arr2){
            res^=num;
        }

        int ans=0;
        for(int num:arr1){
            ans^=num&res;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n[6,5]\n
// @lcpr case=end

// @lcpr case=start
// [12]\n[4]\n
// @lcpr case=end

 */

