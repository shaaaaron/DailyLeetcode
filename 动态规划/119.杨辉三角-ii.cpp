/*
 * @lc app=leetcode.cn id=119 lang=cpp
 * @lcpr version=30121
 *
 * [119] 杨辉三角 II
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
    vector<int> getRow(int rowIndex) {
        vector<int> dp (1,1); // 初始化方式，为1

        for(int i=1; i<=rowIndex; i++){ // 从长度为i到i+1
            vector<int> nextDp(i+1, 0);
            for(int j=0;j<i+1;j++){
                if(j==0){
                    nextDp[j]=dp[j];
                }else if (j==i){
                    nextDp[j]=dp[j-1];
                }else{
                    nextDp[j]= dp[j-1]+dp[j];
                }
            }
            dp = nextDp;
        }

        return dp;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 0\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

