/*
 * @lc app=leetcode.cn id=3091 lang=cpp
 * @lcpr version=30122
 *
 * [3091] 执行操作使数据元素之和大于等于 K
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
    int minOperations(int k) {
        int lt=0, rt=k;
        while(lt<=rt){
            int md=(lt+rt)/2;
            int tmp;
            if(md%2){
                tmp=(md/2+1)*(md/2+1+1);
            }else{
                tmp=(md/2+1)*(md/2+1);
            }
            if(tmp>=k){
                rt=md-1;
            }else{
                lt=md+1;
            }
        } 
        return lt;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 11\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

