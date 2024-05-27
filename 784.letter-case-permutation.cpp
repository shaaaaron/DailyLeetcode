/*
 * @lc app=leetcode.cn id=784 lang=cpp
 * @lcpr version=30202
 *
 * [784] 字母大小写全排列
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
    vector<string> letterCasePermutation(string s) {
        int n=0;
        for(char x:s){
            if(isalpha(x)) n++;
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// "a1b2"\n
// @lcpr case=end

// @lcpr case=start
// "3z4"\n
// @lcpr case=end

 */

