/*
 * @lc app=leetcode.cn id=1343 lang=cpp
 * @lcpr version=30201
 *
 * [1343] 大小为K且平均值大于等于阈值的子数组数目
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
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int lt=0,rt=0;
        long long sum=0, ans=0;
        while(rt<k){
            sum+=arr[rt];
            rt++;
        }
        if(sum>=(long long )threshold*k) ans++;

        while(rt<arr.size()){
            sum+=arr[rt];
            sum-=arr[lt];
            if(sum>=(long long )threshold*k) ans++;
            rt++;
            lt++;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,2,2,2,5,5,5,8]\n3\n4\n
// @lcpr case=end

// @lcpr case=start
// [11,13,17,23,29,31,7,5,2,3]\n3\n5\n
// @lcpr case=end

 */

