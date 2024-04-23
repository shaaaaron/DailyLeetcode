/*
 * @lc app=leetcode.cn id=2595 lang=cpp
 * @lcpr version=30122
 *
 * [2595] 奇偶位数
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
    vector<int> evenOddBit(int n) {
        vector<int> ans(2);
        int i=0;
        while(n>0){
            if(n%2){
                ans[i]++;
            }
            i=1-i;
            n=n>>1;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 17\n
// @lcpr case=end

// @lcpr case=start
// 2\n
// @lcpr case=end

 */

