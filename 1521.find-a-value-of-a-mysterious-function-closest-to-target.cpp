/*
 * @lc app=leetcode.cn id=1521 lang=cpp
 * @lcpr version=30122
 *
 * [1521] 找到最接近目标值的函数值
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
    int closestToTarget(vector<int>& arr, int target) {
        unordered_set<int> bef;
        int ans=INT_MAX;
        for(int num: arr){
            unordered_set<int> cur{num};
            for(auto it=bef.begin(); it!=bef.end();it++){
                cur.insert(num&*it);
            }

            for(auto it=cur.begin(); it!=cur.end();it++){
                ans=min(ans, abs(*it-target));
            }
        
            bef=cur;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [9,12,3,7,15]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1000000,1000000,1000000]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2,4,8,16]\n0\n
// @lcpr case=end

 */

