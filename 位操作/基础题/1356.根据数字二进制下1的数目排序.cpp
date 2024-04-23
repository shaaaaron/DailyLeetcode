/*
 * @lc app=leetcode.cn id=1356 lang=cpp
 * @lcpr version=30122
 *
 * [1356] 根据数字二进制下1的数目排序
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
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int x, int y){
            return __builtin_popcount(x)<__builtin_popcount(y) ||__builtin_popcount(x)==__builtin_popcount(y) && x<y;
        });
        return arr;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,2,3,4,5,6,7,8]\n
// @lcpr case=end

// @lcpr case=start
// [1024,512,256,128,64,32,16,8,4,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [10000,10000]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,5,7,11,13,17,19]\n
// @lcpr case=end

// @lcpr case=start
// [10,100,1000,10000]\n
// @lcpr case=end

 */

