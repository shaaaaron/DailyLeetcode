/*
 * @lc app=leetcode.cn id=3067 lang=cpp
 * @lcpr version=30203
 *
 * [3067] 在带权树网络中统计可连接服务器对数目
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
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n=edges.size()+1; // 树的节点数=边的数量+1
        vector<unordered_map<int,int>> memo(n);
        for(auto & edge:edges){
            memo[edge[0]][edge[1]]=edge[2];
            memo[edge[1]][edge[0]]=edge[2];
        }
        
        vector<int> ans(n);
        vector<int> visited(n);
        function<int(int, int)> dfs =[&](int root, int pre_sum){
            if(visited[root]) return 0;
            int sum=0;
            visited[root]=1;
            if(pre_sum%signalSpeed==0) sum++;
            
            for(auto [next, cost]:memo[root]){
                sum+=dfs(next, pre_sum+cost);
            }
            return sum;
        };

        for(int i=0;i<n;i++){
            // cout<<"***"<<i<<endl;
            fill(visited.begin(), visited.end(), 0);
            visited[i]=1;
            int node_sum=0;
            for(auto [next, cost]:memo[i]){
                int tmp=dfs(next, cost);
                ans[i]+=node_sum*tmp;
                node_sum+=tmp;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,1,1],[1,2,5],[2,3,13],[3,4,9],[4,5,2]]\n1\n
// @lcpr case=end

// @lcpr case=start
// [[0,6,3],[6,5,3],[0,3,1],[3,2,7],[3,1,6],[3,4,2]]\n3\n
// @lcpr case=end

 */

