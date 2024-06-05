/*
 * @lc app=leetcode.cn id=2938 lang=cpp
 * @lcpr version=30203
 *
 * [2938] 区分黑球与白球
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
    long long minimumSteps(string s) {
        long long ans=0;
        int j=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                ans+=i-j;
                j++;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "101"\n
// @lcpr case=end

// @lcpr case=start
// "100"\n
// @lcpr case=end

// @lcpr case=start
// "0111"\n
// @lcpr case=end

 */

