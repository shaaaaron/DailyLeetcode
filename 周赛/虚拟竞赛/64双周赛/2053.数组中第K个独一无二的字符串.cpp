/*
 * @lc app=leetcode.cn id=2053 lang=cpp
 * @lcpr version=30201
 *
 * [2053] 数组中第K个独一无二的字符串
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
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> memo;
        for(string s:arr){
            memo[s]++;
        }
        
        for(string s:arr){
            if(memo[s]==1){
                k--;
                if(k==0) return s;
            }
        }
        
        return "";
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["d","b","c","b","c","a"]\n2\n
// @lcpr case=end

// @lcpr case=start
// ["aaa","aa","a"]\n1\n
// @lcpr case=end

// @lcpr case=start
// ["a","b","a"]\n3\n
// @lcpr case=end

 */

