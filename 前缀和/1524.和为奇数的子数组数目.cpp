/*
 * @lc app=leetcode.cn id=1524 lang=cpp
 * @lcpr version=30122
 *
 * [1524] 和为奇数的子数组数目
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
    int numOfSubarrays(vector<int>& arr) {
        unordered_map<int, int> memo;

        int sum=0;
        long long ans=0;
        const long long PRIME=1000*1000*1000+7;

        memo[0]=1;
        for(int i=0;i<arr.size();i++){
            sum=sum+arr[i];

            if(memo.find(1-sum%2)!=memo.end()){
                ans=(ans+memo.at(1-sum%2))%PRIME;
            }

            memo[sum%2]++;
        }

        return ans;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,5]\n
// @lcpr case=end

// @lcpr case=start
// [2,4,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,6,7]\n
// @lcpr case=end

// @lcpr case=start
// [100,100,99,99]\n
// @lcpr case=end

// @lcpr case=start
// [7]\n
// @lcpr case=end

 */

