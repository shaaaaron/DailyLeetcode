/*
 * @lc app=leetcode.cn id=2269 lang=cpp
 * @lcpr version=30122
 *
 * [2269] 找到一个数字的K美丽值
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
    int divisorSubstrings(int num, int k) {

        int num_size=0; // 计算num的位数
        int tmp=num;
        while(tmp){
            num_size++;
            tmp/=10;
        }

        long long mask=1; // 防止越界。得到k对应的mask
        tmp=k;
        while(tmp){
            tmp--;
            mask*=10;
        }

        int ans=0;
        int rem_test=num_size-k+1;
        tmp=num;
        while(rem_test){
            int now=tmp%mask;
            if(now!=0 && num%now==0) ans++; //0不能作为除数
            tmp/=10;
            rem_test--;
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 240\n2\n
// @lcpr case=end

// @lcpr case=start
// 430043\n2\n
// @lcpr case=end

 */

