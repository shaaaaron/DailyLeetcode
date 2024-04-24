/*
 * @lc app=leetcode.cn id=1503 lang=cpp
 * @lcpr version=30122
 *
 * [1503] 所有蚂蚁掉下来前的最后一刻
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
// 蚂蚁相对碰撞相当于没发生变化
// 因为只要整体状态，不在乎每个蚂蚁的状态
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans=0;// 不要intmax，可能left和right是空
                    // 注意初始化和数组的长度

        for(auto num:left){
            ans=max(num, ans);
        }
        for(auto num:right){
            ans=max(n-num, ans);
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n[4,3]\n[0,1]\n
// @lcpr case=end

// @lcpr case=start
// 7\n[]\n[0,1,2,3,4,5,6,7]\n
// @lcpr case=end

// @lcpr case=start
// 7\n[0,1,2,3,4,5,6,7]\n[]\n
// @lcpr case=end

 */

