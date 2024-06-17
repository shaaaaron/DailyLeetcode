/*
 * @lc app=leetcode.cn id=312 lang=cpp
 * @lcpr version=30121
 *
 * [312] 戳气球
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
    // 考虑哪个气球是最后戳破的
    // a[i][j] 表示开区间(i,j)戳破其中的所有气球（不包括边界），能取得的最大硬币数
    // 给左边右边分别添加一个虚拟气球
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> a (n, vector<int>(n,0));

        // for(int i=0;i<n;i++) a[i][i]=0;

        for(int d_ij=1;d_ij<=n-1;d_ij++){ // 注意从1而不是0开始
            for(int i=0,j=i+d_ij;j<n;i++,j++){
                for(int tmp=i;tmp<=j;tmp++){
                    // tmp是最后炸爆的
                    if(tmp==i){
                        a[i][j]=max(a[i][j], nums[tmp]*a[i+1][j]);// 越界
                    }else if(tmp==j){
                        a[i][j]=max(a[i][j], nums[tmp]*a[i][j-1]);
                    }else{
                        a[i][j]=max(a[i][j], nums[tmp]*a[i][tmp-1]+nums[tmp]*a[tmp+1][j]);
                    }
                }
            }
        }

        return a[0][n-1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,1,5,8]\n
// @lcpr case=end

// @lcpr case=start
// [1,5]\n
// @lcpr case=end

 */

