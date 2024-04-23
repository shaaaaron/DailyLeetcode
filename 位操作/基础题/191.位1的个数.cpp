/*
 * @lc app=leetcode.cn id=191 lang=cpp
 * @lcpr version=30122
 *
 * [191] 位1的个数
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
    int hammingWeight(int n) {
        int ans=0;
        while(n){
            if(n&1)ans++;
            n/=2;
        }
        return ans;
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// 11\n
// @lcpr case=end

// @lcpr case=start
// 128\n
// @lcpr case=end

// @lcpr case=start
// 2147483645\n
// @lcpr case=end

 */

