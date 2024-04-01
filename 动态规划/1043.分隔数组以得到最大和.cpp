/*
 * @lc app=leetcode.cn id=1043 lang=cpp
 * @lcpr version=30121
 *
 * [1043] 分隔数组以得到最大和
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
    int maxSumAfterPartitioning(vector<int>& arr, int len) {
        // 长度是500， N^3时间复杂度可以接受
        int n =arr.size();
        vector<int> dp(n+1, 0); // 额外缩进了一步，dp数组包含状态0，但是原数组arr不含
        // 这一步是可以的，标准答案也是这么写的
        // dp[n]表示第n个元素结尾的最大值，但实际上的第n个元素是arr[n-1]，访问arr的时候注意就行了
        // 这样才好利用dp[0]=0进行初始化 

        for(int i=1;i<=n;i++){
            int tmpMax = arr[i-1]; // tmpmax选择在从后往前的过程中遍历，可以将时间复杂度优化到-1
            for(int j=1;j<=len && j<=i;j++){ // 不能超过下标
                tmpMax=max(tmpMax, arr[i-1 -j+1]);
                dp[i]=max(dp[i-j]+j*tmpMax, dp[i]);
            }
        }

        return dp[n];
        // 下面是N^3时间，max求的过程可以优化
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=len && j<=i;j++){ // 不能超过下标
        //         int tmpMax=arr[i-1 ]; // arr访问要手动调整-1
        //         for(int k=0;k<j;k++){ 
        //             tmpMax=max(tmpMax, arr[i-1 -k]);
        //         }
        //         dp[i]=max(dp[i-j]+j*tmpMax, dp[i]);
        //     }
        // }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,15,7,9,2,5,10]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,4,1,5,7,3,6,1,9,9,3]\n4\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */

