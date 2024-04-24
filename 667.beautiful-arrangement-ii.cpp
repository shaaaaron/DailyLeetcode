/*
 * @lc app=leetcode.cn id=667 lang=cpp
 * @lcpr version=30122
 *
 * [667] 优美的排列 II
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
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        int left=n, right=n-k;
        int minval=INT_MAX;

        // 在状态机、两个一起两个方法里选两个一起
        while(left>=right){
            if(left>right){
                ans.push_back(left);
                ans.push_back(right);
                minval=min(minval, right);
            }else if(left==right){
                ans.push_back(left);
                minval=min(minval, left);
            }
            left--;
            right++;
        }

        minval--;
        while(minval>0){
            ans.push_back(minval);
            minval--;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 100\n99\n
// @lcpr case=end
// @lcpr case=start
// 100\n10\n
// @lcpr case=end
// @lcpr case=start
// 33\n1\n
// @lcpr case=end
// @lcpr case=start
// 33\n3\n
// @lcpr case=end
// @lcpr case=start
// 3\n1\n
// @lcpr case=end

// @lcpr case=start
// 3\n2\n
// @lcpr case=end

 */

