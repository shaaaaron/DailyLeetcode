/*
 * @lc app=leetcode.cn id=2952 lang=cpp
 * @lcpr version=30121
 *
 * [2952] 需要添加的硬币的最小数量
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
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());   // 记得排序啊

        int n = coins.size();
        int money = 0;
        int ans=0;
        int i=0; // 使用的给定的硬币数量，下一个硬币的位置
        while(1){
            if(money>=target)break;
            if(i<n && money+1>=coins[i]){
                money = money+coins[i];
                i++;
            }else{
                int tmp=money+1;
                money = money+tmp;
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,4,10]\n19\n
// @lcpr case=end

// @lcpr case=start
// [1,4,10,5,7,19]\n19\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1]\n20\n
// @lcpr case=end

// @lcpr case=start
// [1]\n11\n
// @lcpr case=end
 */

