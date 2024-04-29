/*
 * @lc app=leetcode.cn id=2433 lang=cpp
 * @lcpr version=30122
 *
 * [2433] 找出前缀异或的原始数组
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
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans;
        for(int i=0;i<pref.size();i++){
            if(i==0)
                ans.push_back(pref[i]);
            else    
                ans.push_back(pref[i]^pref[i-1]);
        } 
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,2,0,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [13]\n
// @lcpr case=end

 */

