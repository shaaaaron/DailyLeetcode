/*
 * @lc app=leetcode.cn id=2981 lang=cpp
 * @lcpr version=30202
 *
 * [2981] 找出出现至少三次的最长特殊子字符串 I
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
    int maximumLength(string s) {
        int n=s.size();
        int ans=-1;
        unordered_map<string, int> memo;
        for(int i=0;i<n;i++){
            string tmp;
            for(int j=i;j<n && s[i]==s[j];j++){
                tmp+=s[j]; // 可以直接追加char，不一定需要追加string
                memo[tmp]++;
            }
        }

        for(auto [k, v]:memo){
            if(v>=3){
                ans=max(ans, (int)k.size()); // 必须int强制类型转化
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aaaa"\n
// @lcpr case=end

// @lcpr case=start
// "abcdef"\n
// @lcpr case=end

// @lcpr case=start
// "abcaba"\n
// @lcpr case=end

 */

