/*
 * @lc app=leetcode.cn id=1720 lang=cpp
 * @lcpr version=30122
 *
 * [1720] 解码异或后的数组
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
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ori{first};
        for(int i=0;i<encoded.size();i++){
            ori.push_back(ori[i]^encoded[i]);
        }   
        return ori;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n1\n
// @lcpr case=end

// @lcpr case=start
// [6,2,7,3]\n4\n
// @lcpr case=end

 */

