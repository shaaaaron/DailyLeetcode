/*
 * @lc app=leetcode.cn id=881 lang=cpp
 * @lcpr version=30202
 *
 * [881] 救生艇
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
    int numRescueBoats(vector<int>& people, int limit) {
        int i=0, j=people.size()-1;
        int ans=0;
        sort(people.begin(), people.end());
        while(i<=j){
            if(people[i]+people[j]>limit){
                ans++;
                j--;
            }else if(people[i]+people[j]<=limit){
                ans++;
                i++;
                j--;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [3,2,2,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [3,5,3,4]\n5\n
// @lcpr case=end

 */

