/*
 * @lc app=leetcode.cn id=1422 lang=cpp
 * @lcpr version=30122
 *
 * [1422] 分割字符串的最大得分
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
    int count(string s, char x){
        int ans=0;
        for(char ch:s){
            if(ch==x)ans++;
        }
        return ans;
    }

    int maxScore(string s) {
        int ans=0;
        for(int i=0;i+1<s.size();i++){
            int a=count(s.substr(0,i+1), '0'); //能处理先导零
            int b=count(s.substr(i+1), '1');
            ans=max(ans, a+b);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "011101"\n
// @lcpr case=end

// @lcpr case=start
// "00111"\n
// @lcpr case=end

// @lcpr case=start
// "1111"\n
// @lcpr case=end

 */

