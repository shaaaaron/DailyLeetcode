/*
 * @lc app=leetcode.cn id=1557 lang=cpp
 * @lcpr version=30122
 *
 * [1557] 可以到达所有点的最少点数目
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
// 注意题目是有向无环图
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> in(n);
        for(auto&eg:edges){
            in[eg[1]]++;
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!in[i])
                ans.push_back(i);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 6\n[[0,1],[0,2],[2,5],[3,4],[4,2]]\n
// @lcpr case=end

// @lcpr case=start
// 5\n[[0,1],[2,1],[3,1],[1,4],[2,4]]\n
// @lcpr case=end

 */

