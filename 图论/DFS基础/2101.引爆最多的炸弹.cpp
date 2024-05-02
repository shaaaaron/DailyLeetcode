/*
 * @lc app=leetcode.cn id=2101 lang=cpp
 * @lcpr version=30122
 *
 * [2101] 引爆最多的炸弹
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
    int n;
    vector<unordered_map<int,int>> memo;

    bool check(vector<int>&x, vector<int>&y){
        double dx=x[0]-y[0];
        double dy=x[1]-y[1];
        double  r=x[2];
        return dx*dx+dy*dy<=r*r;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        n=bombs.size();
        memo.resize(n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==i) continue;
                if(check(bombs[i], bombs[j])){
                    memo[i][j]=1;
                }
            }
        }

        int ans=0;
        for(int i=0;i<n;i++){
            vector<int> vis(n);
            int cur_ans=0;

            function<void(int)> dfs=[&](int n){
                vis[n]=1;
                cur_ans++;
                for(auto& eg:memo[n]){
                    int next=eg.first;
                    if(vis[next]!=1)
                        dfs(next);
                }
            };

            dfs(i);
            ans=max(ans, cur_ans);
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,1,100000],[100000,100000,1]]\n
// @lcpr case=end
// @lcpr case=start
// [[2,1,3],[6,1,4]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,5],[10,10,5]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[2,3,1],[3,4,2],[4,5,3],[5,6,4]]\n
// @lcpr case=end

 */

