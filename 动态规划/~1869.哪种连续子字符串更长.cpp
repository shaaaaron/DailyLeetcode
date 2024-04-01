/*
 * @lc app=leetcode.cn id=1869 lang=cpp
 * @lcpr version=30121
 *
 * [1869] 哪种连续子字符串更长
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
    bool checkZeroOnes(string s) {
        int num=0, lastnum=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                lastnum++;
                num=max(num, lastnum); // 使用到当前为止的字符串的长度，而不是lastidx
                // 这样可以在每个时间步都max，不需要对最后的时间n特殊处理
                // 天才，多练，想清除dp维护的数据含义
            }else{
                lastnum=0;
            }
        }

        int num2=0;
        lastnum=0; // 不能重定义
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                lastnum++;
                num2=max(num2, lastnum);
            }else{
                lastnum=0;
            }
        }

        return num<num2;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "1101"\n
// @lcpr case=end

// @lcpr case=start
// "111000"\n
// @lcpr case=end

// @lcpr case=start
// "110100010"\n
// @lcpr case=end

 */

