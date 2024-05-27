/*
 * @lc app=leetcode.cn id=2028 lang=cpp
 * @lcpr version=30202
 *
 * [2028] 找出缺失的观测数据
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
#include <algorithm>
#include <algorithm>
#include <numeric>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        int sum=(m+n)*mean;
        sum-=accumulate(rolls.begin(), rolls.end(), 0); // #include <numeric>
        if(sum<n || sum>6*n) return {}; // 是1到6，不是0到5
        vector<int> ans(n, sum/n);
        for(int i=0;i<sum%n;i++){
            ans[i]++;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,2,2,5,4,5,4,5,3,3,6,1,2,4,2,1,6,5,4,2,3,4,2,3,3,5,4,1,4,4,5,3,6,1,5,2,3,3,6,1,6,4,1,3]\n2\n53\n
// @lcpr case=end
// @lcpr case=start
// [3,2,4,3]\n4\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,5,6]\n3\n4\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n6\n4\n
// @lcpr case=end

// @lcpr case=start
// [1]\n3\n1\n
// @lcpr case=end

 */

