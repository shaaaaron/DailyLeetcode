/*
 * @lc app=leetcode.cn id=2024 lang=cpp
 * @lcpr version=30204
 *
 * [2024] 考试的最大困扰度
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
    int maxConsecutiveAnswers(string answerKey, int k) {
        unordered_map<char, int> memo;
        memo['T'] = 0;
        memo['F'] = 0;

        int lt=0, rt=0;
        int ans=0;
        for(rt=0; rt<answerKey.size(); rt++){
            memo[answerKey[rt]] ++ ;
            if(memo['T']>k and memo['F']>k){
                memo[answerKey[lt]] --;
                lt++;
            }
            // [lt, rt]是当前的满足条件的子串
            ans = max(ans, memo['T']+memo['F']);
        }

        return ans;
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// "TTFF"\n2\n
// @lcpr case=end

// @lcpr case=start
// "TFFT"\n1\n
// @lcpr case=end

// @lcpr case=start
// "TTFTTFTT"\n1\n
// @lcpr case=end

 */

