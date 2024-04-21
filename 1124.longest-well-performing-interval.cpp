/*
 * @lc app=leetcode.cn id=1124 lang=cpp
 * @lcpr version=30122
 *
 * [1124] 表现良好的最长时间段
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
    int longestWPI(vector<int>& hours) {
        int sum=0; // 劳累的天数 超过 不劳累天数的 数量
        int ans=0;

        unordered_map<int,int> memo; // 只需要记录小于0的天数的坐标
        // memo[0]=-1;

        for(int i=0;i<hours.size();i++){
            if(hours[i]>8){
                sum++;
            }else{
                sum--;
            }

            if(sum>0){
                ans=max(i+1,ans);
            }else{
                if(memo.find(sum-1)!=memo.end()){
                    ans=max(ans, i-memo[sum-1]);
                }
            }

            if(memo.find(sum)==memo.end()){
                memo[sum]=i;
            }
        }
        
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [9,9,6,0,6,6,9]\n
// @lcpr case=end

// @lcpr case=start
// [6,6,6]\n
// @lcpr case=end

 */

