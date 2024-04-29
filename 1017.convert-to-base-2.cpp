/*
 * @lc app=leetcode.cn id=1017 lang=cpp
 * @lcpr version=30122
 *
 * [1017] 负二进制转换
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
#include <cmath>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    string baseNeg2(int n) {
        if(n==0) return "0";

        string ans;

        int base=-2;
        while(n!=0){
            int cur=(n%2+2)%2;        
            ans=string(1, '0'+cur)+ans;
            n=(n-cur)/(-2); // 减去0或者1，一个非负数
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 4\n
// @lcpr case=end

 */

