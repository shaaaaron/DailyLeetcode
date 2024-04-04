/*
 * @lc app=leetcode.cn id=1475 lang=cpp
 * @lcpr version=30121
 *
 * [1475] 商品折扣后的最终价格
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
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans=prices;
        stack<int> s;
        for(int i=0;i<prices.size();i++){
            while(!s.empty() && prices[s.top()]>=prices[i]){
                ans[s.top()]-=prices[i];
                s.pop();
            }
            s.push(i); // 统一idx
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [8,4,6,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [10,1,1,6]\n
// @lcpr case=end

 */

