/*
 * @lc app=leetcode.cn id=1768 lang=cpp
 * @lcpr version=30122
 *
 * [1768] 交替合并字符串
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
    string mergeAlternately(string word1, string word2) {
        string ans;
        int i;
        for(i=0;i<min(word1.size(), word2.size());i++){
            ans+=string(1, word1[i]);
            ans+=string(1, word2[i]);
        }

        // str.substr(str.size()) 对应空字符串，不会报错
        if(i>=word1.size())
            ans+=word2.substr(i);
        if(i>=word2.size())
            ans+=word1.substr(i);


        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abc"\n"pqr"\n
// @lcpr case=end

// @lcpr case=start
// "ab"\n"pqrs"\n
// @lcpr case=end

// @lcpr case=start
// "abcd"\n"pq"\n
// @lcpr case=end

 */

