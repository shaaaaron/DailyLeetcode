/*
 * @lc app=leetcode.cn id=877 lang=cpp
 * @lcpr version=30121
 *
 * [877] 石子游戏
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
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> a(n,vector<int>(n,0));  // 先手能拿到的分数和后手之差

        for(int d_ij=0; d_ij<=n-1;d_ij++){
            for(int i=0,j=i+d_ij; j<n;i++,j++){ // 同时ij
                if(d_ij==0){
                    a[i][j] = piles[i];
                }else{
                    a[i][j] = max(piles[i]-a[i+1][j], piles[j]-a[i][j-1]); // 想好如何进行区间dp
                }
            }
        }
        return a[0][n-1]>0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [3,7,2,3]\n
// @lcpr case=end

 */

