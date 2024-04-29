/*
 * @lc app=leetcode.cn id=898 lang=cpp
 * @lcpr version=30122
 *
 * [898] 子数组按位或操作
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
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans;
        unordered_set<int> bef;
        for(int num:arr){
            unordered_set<int> cur={num};
            for(auto it=bef.begin();it!=bef.end();it++){
                cur.insert( (*it) | num);
            }

            for(auto it=cur.begin();it!=cur.end();it++){
                ans.insert(*it);
            }

            bef=cur; // 更新
        }

        return ans.size();
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,4]\n
// @lcpr case=end

 */

