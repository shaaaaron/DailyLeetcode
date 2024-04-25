/*
 * @lc app=leetcode.cn id=970 lang=cpp
 * @lcpr version=30122
 *
 * [970] 强整数
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
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> memo(bound+10);
        int i=1,j;

        while(i<=bound){
            j=1;
            while(i+j<=bound){
                memo[i+j]=1;
                j*=y;

                if(y==1)break; // 如果为1一次就退出
            }
            i*=x;

            if(x==1)break; // 如果为1一次就退出
        }

        vector<int> ans;
        for(int i=2;i<=bound;i++){
            if(memo[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n3\n10\n
// @lcpr case=end

// @lcpr case=start
// 3\n5\n15\n
// @lcpr case=end
// @lcpr case=start
// 2\n1\n10\n
// @lcpr case=end
// @lcpr case=start
// 1\n1\n10\n
// @lcpr case=end
// @lcpr case=start
// 1\n2\n10\n
// @lcpr case=end

 */

