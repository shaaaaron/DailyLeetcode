/*
 * @lc app=leetcode.cn id=650 lang=cpp
 * @lcpr version=30121
 *
 * [650] 两个键的键盘
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

// 素因子分解，如果有素因子，必然体现为一整次复制粘贴
class Solution {
public:
    int minSteps(int n) {
        if(n==1){
            return 0;
        }

        int ans =0;
        int fac=2;
        while(n!=1){
            if(n%fac == 0){
                n = n / fac;
                ans+= fac;
            }else{
                fac++;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

