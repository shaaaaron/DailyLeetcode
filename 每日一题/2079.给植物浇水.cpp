/*
 * @lc app=leetcode.cn id=2079 lang=cpp
 * @lcpr version=30201
 *
 * [2079] 给植物浇水
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
    int wateringPlants(vector<int>& plants, int capacity) {
        int loc=0, water=capacity;
        int n=plants.size(), ans=1;
        while(loc<n){
            // 保证水是足够当前植物
            water-=plants[loc];
            if(loc+1<n && water<plants[loc+1]){
                ans+=2*(loc+1);
                water=capacity;
            }

            if(loc==n-1) break;
            loc++;
            ans++;
        }   
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2]\n100\n
// @lcpr case=end
// @lcpr case=start
// [2,2,3,3]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,4,2,3]\n4\n
// @lcpr case=end

// @lcpr case=start
// [7,7,7,7,7,7,7]\n8\n
// @lcpr case=end

 */

