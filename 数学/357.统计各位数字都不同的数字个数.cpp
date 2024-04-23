/*
 * @lc app=leetcode.cn id=357 lang=cpp
 * @lcpr version=30122
 *
 * [357] 统计各位数字都不同的数字个数
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
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        if(n==1) return 10;
        int ans=10;
        for(int i=2;i<=n;i++){
            int tmp=9;
            int factor=9;
            while(factor>=11-i){
                tmp*=factor;
                factor--;
            }
            ans+=tmp;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end
// @lcpr case=start
// 4\n
// @lcpr case=end
// @lcpr case=start
// 5\n
// @lcpr case=end
// @lcpr case=start
// 6\n
// @lcpr case=end
// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 2\n
// @lcpr case=end
// @lcpr case=start
// 0\n
// @lcpr case=end

 */

