/*
 * @lc app=leetcode.cn id=1318 lang=cpp
 * @lcpr version=30122
 *
 * [1318] 或运算的最小翻转次数
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
    int minFlips(int a, int b, int c) {
        int ans=0;
        while(a!=0 || b!=0 || c!=0){
            if(c%2==0){
                ans+=(a&1)+(b&1);
            }else{
                ans+= (a&1)==0 && (b&1)==0 ?1:0;
            }
            a>>=1;
            b>>=1;
            c>>=1;
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n6\n5\n
// @lcpr case=end

// @lcpr case=start
// 4\n2\n7\n
// @lcpr case=end

// @lcpr case=start
// 1\n2\n3\n
// @lcpr case=end

 */

