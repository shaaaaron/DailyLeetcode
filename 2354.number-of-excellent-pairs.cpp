/*
 * @lc app=leetcode.cn id=2354 lang=cpp
 * @lcpr version=30122
 *
 * [2354] 优质数对的数目
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
#include <map>
#include <set>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        set<int> num_set;// 不用顺序
        map<int,int> memo;
        for(int num:nums){
            num_set.insert(num);
        }

        for(auto it=num_set.begin(); it!=num_set.end(); it++){
            if(__builtin_popcount(*it)>=k+1)
                memo[k+1]++;
            else
                memo[__builtin_popcount(*it)]++;
        }

        int ans=0;
        int sum=0;
        for(int i=0;i<=k+1;i++){ // 聚合一下，其实不聚合也可以，因为最多32位32
            for(int j=0;j<=k+1;j++){
                if(memo.find(i)==memo.end()) continue;
                if(memo.find(j)==memo.end()) continue;
                if(i+j<k) continue;
                ans+=memo[i]*memo[j];
            }
        }
        return ans;//注意返回值和中间值是longlong
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [5,1,1]\n10\n
// @lcpr case=end

 */

