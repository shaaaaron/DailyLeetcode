/*
 * @lc app=leetcode.cn id=982 lang=cpp
 * @lcpr version=30122
 *
 * [982] 按位与为零的三元组
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
// memo可以处理有序/无序的情况
// 先把前n-1个记录，最后枚举最后一个
// 如果sum直接找，如果集合则按下面枚举
    int countTriplets(vector<int>& nums) {
        unordered_map<int,int> memo;
        for(int x:nums){
            for(int y:nums){
                memo[x&y]++;
            }
        }

        int ans=0;
        for(int x:nums){
            x^=0xffff; //数据范围

            // 其实do while更方便
            int cur=x;
            if(memo.find(cur)!=memo.end())
                ans+=memo[cur];
            cur=(cur-1)&x;  // 重要，注意-1反转后面的0，直到反转一个1

            while(cur!=x){
                if(memo.find(cur)!=memo.end())
                    ans+=memo[cur];
                cur=(cur-1)&x;  // 重要，注意-1反转后面的0，直到反转一个1
                                // 由于mask，起到相同的功能
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0]\n
// @lcpr case=end

 */

