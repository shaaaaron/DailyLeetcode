/*
 * @lc app=leetcode.cn id=2730 lang=cpp
 * @lcpr version=30201
 *
 * [2730] 找到最长的半重复子字符串
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
    int longestSemiRepetitiveSubstring(string s) {
        int lt=0, rt=0;
        int ans=0;
        // vector<int> memo(10);
        int unq=0; // 相等的相邻字符的数量
        while(rt<s.size()){
            if(rt>lt && s[rt]==s[rt-1]){
                unq++;
            }
            while(unq>1){ // 如果出现了半重复，那么至少存在两个字符
                if(s[lt]==s[lt+1]){
                    unq--;
                }
                lt++;
            }
            ans=max(rt-lt+1, ans);
            rt++;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "52233"\n
// @lcpr case=end

// @lcpr case=start
// "5494"\n
// @lcpr case=end

// @lcpr case=start
// "1111111"\n
// @lcpr case=end

 */

