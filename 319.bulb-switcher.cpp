/*
 * @lc app=leetcode.cn id=319 lang=cpp
 * @lcpr version=30122
 *
 * [319] 灯泡开关
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
    int bulbSwitch(int n) {
        if(n==0) return 0;
        long long left=1, right=n;
        while(left<=right){
            long long mid= left +(right-left)/2; //防止越界，使用减法和longlong 
            if(mid*mid>n){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        cout<<left<<endl; //严格大 left^2>n
        return int(left-1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 0\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

