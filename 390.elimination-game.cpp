/*
 * @lc app=leetcode.cn id=390 lang=cpp
 * @lcpr version=30122
 *
 * [390] 消除游戏
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
    int lastRemaining(int num) {
        // 和约瑟夫环最大的区别在于，约瑟夫环是环，本题是往返交替进行的
        int left=1, right=num;
        bool left2right=true;

        int ans=0, bit=0;
        while(left<right){
            int tmp= left2right? left: right;

            if(tmp%2==0){ // 0被删除，1剩下
                ans+=1<<bit;
            }
            cout<<left<<","<<right<<","<<ans<<endl;

            if(tmp%2==0){
                if(right%2==0){
                    right--;
                }
            }else{
                if(left%2==1){
                    left++;
                }
            }
            left=left>>1;
            right=right>>1;
            
            bit++;
            left2right=!left2right;
        }
        return ans+(left<<bit); //吐了，移位运算符优先级
        // 注意left之前的位也要加上
    }
};
// @lc code=end



/*
// @lcpr case=start
// 9\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end
// @lcpr case=start
// 2\n
// @lcpr case=end
// @lcpr case=start
// 3\n
// @lcpr case=end
// @lcpr case=start
// 4\n
// @lcpr case=end
// @lcpr case=start
// 5\n
// @lcpr case=end
// @lcpr case=start
// 6\n
// @lcpr case=end
// @lcpr case=start
// 7\n
// @lcpr case=end
// @lcpr case=start
// 8\n
// @lcpr case=end
// @lcpr case=start
// 10\n
// @lcpr case=end

 */

