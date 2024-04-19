/*
 * @lc app=leetcode.cn id=455 lang=cpp
 * @lcpr version=30122
 *
 * [455] 分发饼干
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
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());// 孩子
        sort(s.begin(), s.end());// 饼干
        int gi=0, si=0;
        int ans=0;
        while(gi<g.size() && si<s.size()){ // 能够贪心的做，是因为小孩子只需要喂饱，一块饼干没吃完的部分不会影响，无后效性。
            if(s[si]>=g[gi]){
                ans++;
                gi++;
                si++;
            }else{
                si++;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n[1,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[1,2,3]\n
// @lcpr case=end

 */

