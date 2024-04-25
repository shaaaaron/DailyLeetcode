/*
 * @lc app=leetcode.cn id=2739 lang=cpp
 * @lcpr version=30122
 *
 * [2739] 总行驶距离
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
    // int distanceTraveled(int mainTank, int additionalTank) {
    //     int ans=0;
    //     while(mainTank>0){
    //         if(mainTank>=5){
    //             ans+=5;
    //             mainTank-=5;
    //             if(additionalTank>=1){
    //                 mainTank++;
    //                 additionalTank--;
    //             }
    //         }else{
    //             ans+=mainTank;
    //             mainTank=0;
    //         }
    //     }
    //     return 10*ans;
    // }
    int distanceTraveled(int mainTank, int additionalTank) {
        int tmp=(mainTank-1)/(5-1);

        // while(tmp>0){
        //     oil_from_add+=tmp;
        //     tmp/=5;
        // } 错误的，余数没有正确用上
        
        return 10*(mainTank+ min(tmp, additionalTank));
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n10\n
// @lcpr case=end
// @lcpr case=start
// 9\n2\n
// @lcpr case=end

// @lcpr case=start
// 1\n2\n
// @lcpr case=end

 */

