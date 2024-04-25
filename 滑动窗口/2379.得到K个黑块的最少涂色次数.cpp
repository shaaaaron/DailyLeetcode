/*
 * @lc app=leetcode.cn id=2379 lang=cpp
 * @lcpr version=30122
 *
 * [2379] 得到K个黑块的最少涂色次数
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
    int minimumRecolors(string blocks, int k) {
        int lt=0, rt=0;
        int ans, sum=0; // ans计算答案，sum计算白块的数量

        while(rt<k){
            if(blocks[rt]=='W')
                sum++;
            rt++;
        }
        ans=sum;

        while(rt<blocks.size()){
            if(blocks[rt]=='W') sum++;
            if(blocks[lt]=='W') sum--;
            rt++;
            lt++;
            ans=min(ans, sum);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "WBBWWBBWBW"\n7\n
// @lcpr case=end

// @lcpr case=start
// "WBWBBBW"\n2\n
// @lcpr case=end

 */

