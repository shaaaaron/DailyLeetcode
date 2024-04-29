/*
 * @lc app=leetcode.cn id=2429 lang=cpp
 * @lcpr version=30122
 *
 * [2429] 最小异或
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
    int minimizeXor(int num1, int num2) {
        // 返回对应的数
        // 变量名不清晰，应该想象怎么写清晰的变量名和注释
        int m=__builtin_popcount(num1), n=__builtin_popcount(num2);
        if(n<=m){// 如果nums2 1更少
            int tmp=num1;
            n=m-n;
            while(n){
                tmp&=(tmp-1);
                n--;
            }
            return tmp;
        }else{// 如果nums2 1更多
            int tmp=0;
            n=n-m;
            int bit=0;
            while(n){
                if((1<<bit &num1)==0){
                    tmp|=1<<bit;
                    n--;
                }
                bit++;
            }
            return tmp|num1;
        }
        return -1;// 
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n5\n
// @lcpr case=end

// @lcpr case=start
// 1\n12\n
// @lcpr case=end

 */

