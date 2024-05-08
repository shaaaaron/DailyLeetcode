/*
 * @lc app=leetcode.cn id=1042 lang=cpp
 * @lcpr version=30201
 *
 * [1042] 不邻接植花
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
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<unordered_set<int>> memo(n);
        for(auto & eg:paths){
            memo[eg[0]-1].insert(eg[1]-1);
            memo[eg[1]-1].insert(eg[0]-1);
        }

        // 没有环方可拓扑排序，有环不行
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int bit_check=0;
            for(int next:memo[i]){
                if(ans[next]){
                    bit_check|=1<<ans[next];
                }
            }
            for(int color=4;color>=1;color--){
                if((bit_check & 1<<color) ==0){
                    ans[i]=color;
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n[[1,2],[2,3],[3,1]]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[[1,2],[3,4]]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]\n
// @lcpr case=end

 */

