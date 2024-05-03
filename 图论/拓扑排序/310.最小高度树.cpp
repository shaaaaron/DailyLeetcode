/*
 * @lc app=leetcode.cn id=310 lang=cpp
 * @lcpr version=30122
 *
 * [310] 最小高度树
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
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0}; //此时没有边 

        vector<int> in(n); // 表示连通到点的数量，1则是边界点，其他是中心点
        unordered_map<int, set<int>> memo(n);

        for(auto &eg:edges){
            memo[eg[0]].insert(eg[1]);
            memo[eg[1]].insert(eg[0]);
            in[eg[0]]++;
            in[eg[1]]++;
        }

        deque<int> dq, pre_dq;
        for(int i=0;i<n;i++){
            if(in[i]==1)
                dq.push_back(i);
        }
        while(!dq.empty()){
            pre_dq=dq;
            int dq_size=dq.size();
            for(int i=0;i<dq_size;i++){
                int cur=dq.front();
                dq.pop_front();
                for(int next:memo[cur]){
                    in[next]--;
                    if(in[next]==1){
                        dq.push_back(next);
                    }
                }
            }
        }

        return vector<int>(pre_dq.begin(), pre_dq.end());
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n[]\n
// @lcpr case=end
// @lcpr case=start
// 4\n[[1,0],[1,2],[1,3]]\n
// @lcpr case=end

// @lcpr case=start
// 6\n[[3,0],[3,1],[3,2],[3,4],[5,4]]\n
// @lcpr case=end

 */

