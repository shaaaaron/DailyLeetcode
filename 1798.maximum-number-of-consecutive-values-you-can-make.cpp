/*
 * @lc app=leetcode.cn id=1798 lang=cpp
 * @lcpr version=30122
 *
 * [1798] 你能构造出连续值的最大数目
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
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int now=0; // 表示[0, now]可以构造出来
        for(int coin:coins){
            if(now>=coin-1){ //如果coin-1不能从now构造出来，则不能从coin以上构造出来
                now+=coin;
            }
        }
        return now+1; //注意最后返回的数量，不是构造的最大值
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,4,10,3,1]\n
// @lcpr case=end

 */

