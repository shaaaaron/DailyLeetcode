/*
 * @lc app=leetcode.cn id=882 lang=cpp
 * @lcpr version=30122
 *
 * [882] 细分图中的可到达节点
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

// 单源最短路，如果能走到u再从u走到v，则虽然v看周边不行，但是u能看到：能走到点一定会被看到一次，虽然未必次次看到。胜利一次就是胜利
// 如果不行，必然每次看不到

// 记录到每个点的距离，然后算就可以了
class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        unordered_map<int, unordered_map<int,int>> memo;
        // for(int i=0;i<n;i++) // 避免vector自己到自己初始化为0，或者MAX导致的越界
        //     for(int j=0;j<n;j++)
        //         memo[i][j]=memo[j][i]=1;

        // 可能存在不连通的边
        for(auto & eg:edges){
            memo[eg[0]][eg[1]]=memo[eg[1]][eg[0]]=eg[2]+1; // 经过边的长度，需要加1
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        vector<int> dis(n, INT_MAX);
        pq.emplace(0, 0);
        dis[0]=0;
        while (!pq.empty()){
            auto [dis_cur, cur]=pq.top();
            pq.pop();
            if(dis_cur> dis[cur]) continue; // 每种只从暂存中取一次

            for(auto [next, cost]:memo[cur]){
                if(cost+dis[cur]<dis[next]){
                    dis[next]=cost+dis[cur];
                    pq.emplace(dis[next], next); // 暂存
                }
            }
        }
        
        int ans=0;
        // 计算每个边上（不包括两个端点）的可到达点数量
        // 只需要遍历被细分的点
        for(auto & eg:edges){
            int i=eg[0], j=eg[1], cnt=eg[2];
            if(dis[i]>maxMoves && dis[j]>maxMoves) continue;
            else if(dis[i]>maxMoves){
                // 显然此时边上的点，最多恰好都被囊括。
                ans+=maxMoves-dis[j];
            }else if(dis[j]>maxMoves){
                ans+=maxMoves-dis[i];
            }else{
                int sum=maxMoves-dis[j]+maxMoves-dis[i];
                if(sum>cnt) sum=cnt;
                ans+=sum;
            }
        }
        
        for(int i=0;i<n;i++){
            if(dis[i]<=maxMoves){
                ans++;
            }
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,1,10],[0,2,1],[1,2,2]]\n6\n3\n
// @lcpr case=end

// @lcpr case=start
// [[0,1,4],[1,2,6],[0,2,8],[1,3,1]]\n10\n4\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,4],[1,4,5],[1,3,1],[2,3,4],[3,4,5]]\n17\n5\n
// @lcpr case=end

 */

