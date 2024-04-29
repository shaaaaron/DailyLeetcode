/*
 * @lc app=leetcode.cn id=2683 lang=cpp
 * @lcpr version=30122
 *
 * [2683] 相邻值的按位异或
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
    bool doesValidArrayExist(vector<int>& derived) {
        int res=0;
        for(int num:derived){
            res^=num;
        }
        return res==0?true:false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [1,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,0]\n
// @lcpr case=end

 */

