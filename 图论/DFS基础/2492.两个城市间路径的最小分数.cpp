/*
 * @lc app=leetcode.cn id=2492 lang=cpp
 * @lcpr version=30122
 *
 * [2492] 两个城市间路径的最小分数
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
#include <set>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<unordered_map<int, int>> memo(n+1); // 注意数据范围
        for(auto & vec:roads){
            memo[vec[0]][vec[1]]=vec[2];
            memo[vec[1]][vec[0]]=vec[2];
        }

        int ans=INT_MAX;
        vector<int> vis(n+1);
        function<void(int)> dfs=[&n, &memo, &dfs, &ans, &vis](int x){
            // 保证x没有遍历过
            vis[x]=1;
            for(auto &pr:memo[x]){
                ans=min(ans, pr.second);
                if(vis[pr.first]) continue;
                dfs(pr.first);
            }
        };

        dfs(1);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n[[1,2,9],[2,3,6],[2,4,5],[1,4,7]]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[[1,2,2],[1,3,4],[3,4,7]]\n
// @lcpr case=end

 */

