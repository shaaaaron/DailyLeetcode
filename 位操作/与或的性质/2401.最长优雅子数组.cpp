/*
 * @lc app=leetcode.cn id=2401 lang=cpp
 * @lcpr version=30122
 *
 * [2401] 最长优雅子数组
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
// 因为长度不同于1521u
// 使用状态压缩可以把n!压缩到2^n
    int longestNiceSubarray(vector<int>& nums) {
        unordered_map<int,int> memo;
        unordered_map<int,int> memo_past;
        int ans=0;

        for(int i=0;i<nums.size();i++){
            int loc=-1;// 最后的重复的位置
            for(int bit=0;bit<31;bit++){
                if(nums[i] & 1<<bit){
                    if(memo.find(bit)!=memo.end()){
                        loc=max(loc, memo[bit]);
                    }

                    if(memo.find(bit)!=memo.end()){
                        memo_past[bit]=memo[bit];
                    }
                    memo[bit]=i; /// 在外面 
                }else{
                    if(memo_past.find(bit)!=memo_past.end()){
                        loc=max(loc, memo_past[bit]);
                    }
                }
            }
            // cout<<i-loc<<endl;
            ans=max(ans, i-loc);
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,8,48,10]\n
// @lcpr case=end

// @lcpr case=start
// [3,1,5,11,13]\n
// @lcpr case=end

 */

