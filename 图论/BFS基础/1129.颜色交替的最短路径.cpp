/*
 * @lc app=leetcode.cn id=1129 lang=cpp
 * @lcpr version=30122
 *
 * [1129] 颜色交替的最短路径
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
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<set<int>> red(n);
        vector<set<int>> blue(n);
        for(auto & vec:redEdges){
            red[vec[0]].insert(vec[1]);
        }
        for(auto & vec:blueEdges){
            blue[vec[0]].insert(vec[1]);
        }

        vector<vector<int>> depth(n, {INT_MAX, INT_MAX});
        vector<vector<int>> vis(n, {0,0});
        depth[0][0]=depth[0][1]=0;
        vis[0][0]=vis[0][1]=1;

        deque<pair<int,int>> dq;
        dq.emplace_back(0,0);
        dq.emplace_back(0,1);
        while(!dq.empty()){
            int cur=dq.front().first, color=dq.front().second;
            // cout<<"#"<<cur<<","<<color<<endl;
            dq.pop_front();
            if(color==0){ //0 表示红色
                for(auto & next:blue[cur]){
                    if(vis[next][1]) continue;
                    vis[next][1]=1;
                    depth[next][1]=min(depth[next][1],depth[cur][0]+1);
                    dq.emplace_back(next, 1);
                }
            }else{
                for(auto & next:red[cur]){
                    if(vis[next][0]) continue;
                    vis[next][0]=1;
                    depth[next][0]=min(depth[next][0],depth[cur][1]+1);
                    dq.emplace_back(next, 0);
                }
            }
        }

        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=min(depth[i][0], depth[i][1]);
            if(ans[i]==INT_MAX)
                ans[i]=-1;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n[[0,1],[1,2],[2,3],[3,4]]\n[[1,2],[2,3],[3,1]]\n
// @lcpr case=end
// @lcpr case=start
// 3\n[[0,1],[1,2]]\n[]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[0,1]]\n[[2,1]]\n
// @lcpr case=end

 */

