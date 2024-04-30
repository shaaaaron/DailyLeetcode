/*
 * @lc app=leetcode.cn id=1760 lang=cpp
 * @lcpr version=30122
 *
 * [1760] 袋子里最少数目的球
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
// 二分答案，巧妙地，关键是注意到答案的单调性和范围
    int minimumSize(vector<int>& nums, int maxOperations) {
        // 直接贪心有问题，具体参考case1
        // 如果greater less则不需要给在pq的初始化参数，给在尖括号里面
        // 如果自定义，则前面decltype或者function， 后面再给cmp
        int lt=1, rt=INT_MAX;
        while(lt<=rt){
            int md=lt+(rt-lt)/2;
            int ops=0;
            for(int num:nums){
                ops+=(num-1)/md;
            }
            if(ops<=maxOperations){
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
// [9]\n2\n
// @lcpr case=end

// @lcpr case=start
// [2,4,8,2]\n4\n
// @lcpr case=end

// @lcpr case=start
// [7,17]\n2\n
// @lcpr case=end

 */

