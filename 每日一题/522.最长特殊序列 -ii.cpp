/*
 * @lc app=leetcode.cn id=522 lang=cpp
 * @lcpr version=30203
 *
 * [522] 最长特殊序列 II
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
    bool issubseq(string &a, string& b){
        // check if a is subseq of b (or not)
        int i=0;
        for(int j=0;j<b.size() && i<a.size();j++){
            if(a[i]==b[j]){
                i++;
                //j++; // j每次都移动，不需要这里++
            }
        }
        return i==a.size(); // 由于是判断子序列，所以这里不需要j，只需要i结束
    }

    int findLUSlength(vector<string>& strs) {
        int ans=-1;
        for(int i=0;i<strs.size();i++){
            int flag=1;
            for(int j=0;j<strs.size();j++){
                if(j==i) continue;
                if(issubseq(strs[i], strs[j])){
                    flag=0;
                    break;
                }
            }
            if(flag) ans=max(ans, (int)strs[i].size());
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["aba","cdc","eae"]\n
// @lcpr case=end

// @lcpr case=start
// ["aaa","aaa","aa"]\n
// @lcpr case=end

 */

