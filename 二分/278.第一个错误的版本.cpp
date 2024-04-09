/*
 * @lc app=leetcode.cn id=278 lang=cpp
 * @lcpr version=30121
 *
 * [278] 第一个错误的版本
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
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lower=1,higher=n;

        while(lower<=higher){
            int middle=lower+(higher-lower)/2;
            if(isBadVersion(middle)==true){
                higher=middle-1;
            }else{
                lower=middle+1;
            }
        }

        return lower;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2126753390\n1702766719\n
// @lcpr case=end
// @lcpr case=start
// 5\n4\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n
// @lcpr case=end

 */

