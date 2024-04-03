/*
 * @lc app=leetcode.cn id=5 lang=cpp
 * @lcpr version=30121
 *
 * [5] 最长回文子串
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
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>> a (n, vector<int>(n, 0)); // [i,j]表示i,j是否是回文子串

        for(int i=0;i<n;i++) a[i][i]=1; // 初始回文子串
        int tmpLen=1, startIdx=0;
        for(int len=1; len<=n-1; len++){ // 先遍历j-i的大小
            for(int i=0,j=len;j<n;i++,j++){     // 再遍历i，j，都写上比较方便
                if(len==1){
                    a[i][j] = s[i]==s[j]?1:0;
                }else{
                    a[i][j] = a[i+1][j-1] && s[i]==s[j] ?1:0;
                }

                if(a[i][j]==1 && len+1>tmpLen){
                    tmpLen = len+1;
                    startIdx = i;
                }
            }
        }
        return s.substr(startIdx, tmpLen);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "babad"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */

