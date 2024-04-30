/*
 * @lc app=leetcode.cn id=2571 lang=cpp
 * @lcpr version=30122
 *
 * [2571] 将整数减少到零需要的最少操作数
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
// 如果0不删除
// 如果1，长度2以上就+，否则直接删除
    int minOperations(int n) {
        long long x=n;// 防止越界
        int ans=0;
        for(int i=0;i<=31;i++){ // 一般不取31，这里进位取到31
            if((x&1<<i)==0) continue;
            if((x&1<<i) && (x&1<<i+1)){
                x+=1<<i;
            }else{
                x-=1<<i;    // 最好别与，直接减去有1的位
                            // 如果与保证其他位位1
            }
            ans++;
        } 
        return ans;
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// 39\n
// @lcpr case=end

// @lcpr case=start
// 54\n
// @lcpr case=end

 */

