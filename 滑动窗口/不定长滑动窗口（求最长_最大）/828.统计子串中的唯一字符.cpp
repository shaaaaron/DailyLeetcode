/*
 * @lc app=leetcode.cn id=828 lang=cpp
 * @lcpr version=30202
 *
 * [828] 统计子串中的唯一字符
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
    int uniqueLetterString(string s) {
        int ans=0;
        vector<vector<int>> memo(26, vector<int>(2, -1));
        for(int i=0;i<26;i++){
            memo[i][0]=memo[i][1]=-1;   // 0是靠前的，1是靠后的
        }

        for(int i=0;i<s.size();i++){
            memo[s[i]-'A'][0]=memo[s[i]-'A'][1];
            memo[s[i]-'A'][1]=i;
            for(int j=0;j<26;j++){
                    ans+=memo[j][1]-memo[j][0];
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "ABC"\n
// @lcpr case=end

// @lcpr case=start
// "ABA"\n
// @lcpr case=end

// @lcpr case=start
// "LEETCODE"\n
// @lcpr case=end

 */

