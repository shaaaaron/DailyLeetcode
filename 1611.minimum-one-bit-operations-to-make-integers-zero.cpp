/*
 * @lc app=leetcode.cn id=1611 lang=cpp
 * @lcpr version=30122
 *
 * [1611] 使整数变为 0 的最少操作次数
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
//https://leetcode.cn/problems/minimum-one-bit-operations-to-make-integers-zero/solutions/435645/hua-shan-yi-tiao-dao-wo-men-di-gui-zhao-zou-by-luc/ 
// 从低位贪心是有问题的，应该按上面的从高到低他信

//https://leetcode.cn/problems/minimum-one-bit-operations-to-make-integers-zero/solutions/849141/bu-liao-jie-ge-lei-ma-yong-dong-tai-gui-2tbgr/
// 根据这个来，两次有帮助，三次没帮助，有帮助/没帮助交替进行
    int minimumOneBitOperations(int n) {
        vector<int> dp(31);
        dp[0]=1;
        for(int i=1;i<31;i++){ // 将1000转化为0000和0000转化为1000的操作数
            dp[i]=2*dp[i-1]+1;
        }

        int ans=0; // 贪心求出来的不是最优的结果
        // long long x=n;//防止移位越界
        // while(x){
        //     if( (x&(-x))<<1 & x){ // 末尾连续1
        //         ans++;
        //         x&=~((x&(-x))<<1);
        //     }else{
        //         ans+=dp[31-__builtin_clz(x)];
        //         x&=~(x&(-x));
        //     }
        //     // cout<<ans<<endl;
        // }
        bool plus=true;
        for(int i=30;i>=0;i--){
            if( !(n&1<<i)) continue;
            if(plus){
                ans+=dp[i];
            }else{
                ans-=dp[i];
            }
            plus=!plus;
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n
// @lcpr case=end
// @lcpr case=start
// 999999999\n
// @lcpr case=end
// @lcpr case=start
// 0\n
// @lcpr case=end
// @lcpr case=start
// 2\n
// @lcpr case=end
// @lcpr case=start
// 123124\n
// @lcpr case=end
// @lcpr case=start
// 312\n
// @lcpr case=end
// @lcpr case=start
// 125345\n
// @lcpr case=end
// @lcpr case=start
// 123234\n
// @lcpr case=end
// @lcpr case=start
// 128\n
// @lcpr case=end
// @lcpr case=start
// 3\n
// @lcpr case=end
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 6\n
// @lcpr case=end

 */

