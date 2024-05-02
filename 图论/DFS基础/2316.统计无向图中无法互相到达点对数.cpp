/*
 * @lc app=leetcode.cn id=2316 lang=cpp
 * @lcpr version=30122
 *
 * [2316] 统计无向图中无法互相到达点对数
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
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> vis; // 并查集怎么查每个并查集的数量
        vector<vector<int>> memo(n); // edges只存边，需要转化为邻接表
        for(auto & eg:edges){
            memo[eg[0]].push_back(eg[1]);
            memo[eg[1]].push_back(eg[0]);
        }
        vis.resize(n);

        long long cur_num=0;
        function<void(int)> dfs=[&vis, &cur_num, &memo, &dfs](int node){// 进来的点保证没有访问
            cur_num+=1;
            vis[node]=1;

            for(int next:memo[node]){
                if(vis[next]) continue;
                dfs(next);
            }
        };// lambda不能通过&vis捕获类成员变量，但可以[this]提供访问所在的类
        // 如果递归函数，还需要捕获自己

        vector<long long> union_num;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                cur_num=0;
                dfs(i);
                union_num.push_back(cur_num);
            }
        }
        long long ans=0;
        for(int i=0;i<union_num.size();i++){
            // for(int j=i+1;j<union_num.size();j++){
            //     ans+=union_num[i]*union_num[j]; // 可能越界
            // }
            ans+=union_num[i]*(n-union_num[i]);
        }
        return ans/2;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 100000\n[[1,0],[3,1],[0,4],[2,1]]\n
// @lcpr case=end
// @lcpr case=start
// 5\n[[1,0],[3,1],[0,4],[2,1]]\n
// @lcpr case=end
// @lcpr case=start
// 6\n[[0,1],[2,3],[4,5]]\n
// @lcpr case=end
// @lcpr case=start
// 3\n[[0,1],[0,2],[1,2]]\n
// @lcpr case=end

// @lcpr case=start
// 7\n[[0,2],[0,5],[2,4],[1,6],[5,4]]\n
// @lcpr case=end

 */

