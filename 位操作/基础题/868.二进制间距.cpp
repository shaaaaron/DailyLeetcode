/*
 * @lc app=leetcode.cn id=868 lang=cpp
 * @lcpr version=30122
 *
 * [868] 二进制间距
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
    int binaryGap(int n) {
        int last_idx=-1, idx=0;
        int ans=0;
        while(n){
            if(n&1){
                if(last_idx!=-1){
                    ans=max(ans, idx-last_idx);
                }
                last_idx=idx;
            }
            n/=2;
            idx++;
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 22\n
// @lcpr case=end

// @lcpr case=start
// 8\n
// @lcpr case=end

// @lcpr case=start
// 5\n
// @lcpr case=end

 */

