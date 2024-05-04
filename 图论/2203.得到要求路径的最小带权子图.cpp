/*
 * @lc app=leetcode.cn id=2203 lang=cpp
 * @lcpr version=30122
 *
 * [2203] 得到要求路径的最小带权子图
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
// INT_MAX2e9，本题会超int。本题是1e10，远不到long long max，防止越界使用max的一半
    // long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
    //     unordered_map<int, unordered_map<int,int>> memo;
    //     for(auto & eg:edges){
    //         memo[eg[0]][eg[1]]=eg[2];
    //     }

    //     vector<pair<long long,long long>> dis(n, {LONG_LONG_MAX/2,LONG_LONG_MAX/2});

    //     // 太繁琐了，问问gpt如何简化
    //     // long long换成ll
    //     function<bool( pair<pair<long long,long long>,int>,  pair<pair<long long,long long>,int>)> cmp=[&memo]( pair<pair<long long,long long>,int> x,  pair<pair<long long,long long>,int> y){
    //         return x.first.first+x.first.second >y.first.first+y.first.second;
    //     };
    //     function<bool( pair<long long,long long>,  pair<long long,long long>)> cmp2=[&memo]( pair<long long,long long> x,  pair<long long,long long> y){
    //         return x.first+x.second >y.first+y.second;
    //     };
    //     // auto cmp=[&memo](auto x, auto y){
    //     //     return x.first.first+x.first.second >y.first.first+y.first.second;
    //     // };

    //     priority_queue<pair<pair<long long,long long>,int>, vector<pair<pair<long long,long long>,int>>, function<bool( pair<pair<long long,long long>,int>,  pair<pair<long long,long long>,int>)>> pq(cmp);

    //     dis[src1].first=0;
    //     dis[src2].second=0;
    //     pq.emplace(dis[src1], src1);
    //     pq.emplace(dis[src2], src2);
    //     while(!pq.empty()){
    //         auto [dis_cur, cur]=pq.top();
    //         // pair<long long,long long> dis_cur=pq.top().first;
    //         // int cur=pq.top().second;
    //         pq.pop();
    //         if(cmp2(dis_cur, dis[cur])) continue;

    //         for(auto [next, cost]:memo[cur]){
    //             auto new_dis=dis[cur];
    //             if(new_dis.first!=LONG_LONG_MAX/2){
    //                 new_dis.second+=cost;
    //             }else{
    //                 new_dis.first+=cost;
    //             }

    //             if(cmp2(dis[next], new_dis)){
    //                 dis[next]=new_dis;
    //                 pq.emplace(dis[next], next);
    //             }
    //         }
    //     }



    //     if(dis[dest].first==LONG_LONG_MAX/2 || dis[dest].second==LONG_LONG_MAX/2 )
    //         return -1;
    //     return dis[dest].first+dis[dest].second;
    // }
    // 上面的思路是有问题的，如果(1, max)，则最后都不会找到

    // 问题核心在于思考，在什么地方coincide
    // 三个要点：正确的做法代码量不会大，打了先想清楚
    // 2、重边不影响dijkstra正确性，但是初始化边要注意
    // 3、单源最短路，可能起点开始，也可能终点开始！找所有点到终点的最短路，建立返图。反过来想，从重点开始，建立反图
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        const long long MAX=LONG_LONG_MAX/10; // 大胆放缩，看数据范围
        unordered_map<int, unordered_map<int,int>> memo, memo_inv;
        for(auto & eg:edges){
            // 如果有重边，dijkstra是正确的，但是初始化会出错
            if(memo.find(eg[0])==memo.end() || memo[eg[0]].find(eg[1])==memo[eg[0]].end())
                memo[eg[0]][eg[1]]=INT_MAX;
            memo[eg[0]][eg[1]]=min(memo[eg[0]][eg[1]], eg[2]);

            if(memo_inv.find(eg[1])==memo_inv.end() || memo_inv[eg[1]].find(eg[0])==memo_inv[eg[1]].end())
                memo_inv[eg[1]][eg[0]]=INT_MAX;
            memo_inv[eg[1]][eg[0]]=min(memo_inv[eg[1]][eg[0]], eg[2]);
            // 由于int，所以这里只是intmax，无所谓，立刻就会减小
            // llmax反而越界成为负数，二不会报错。ll赋值int会成为负数，但是不报错
        }

        // dijkstra在负数边可能tle

        vector<long long> dis1(n, MAX);
        vector<long long> dis2(n, MAX);
        vector<long long> dis_dest(n, MAX);
        // 可以单源，也可以终点反图
        // 很怪，还可以终点反图

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq; // 必须greater<>不是greater
        dis1[src1]=0;
        pq.emplace(0, src1);
        while(!pq.empty()){
            auto [dis_cur, cur]=pq.top();
            // cout<<dis_cur<<","<< cur<<endl;
            pq.pop();
            if(dis_cur>dis1[cur]) continue;

            for(auto [next, cost]:memo[cur]){
                if(dis1[cur]+cost< dis1[next]){
                    dis1[next]=dis1[cur]+cost;
                    pq.emplace(dis1[next], next);
                }
            }
        }

        pq=priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>>{}; // pq 不可以clear
        dis2[src2]=0;
        pq.emplace(0, src2);
        while(!pq.empty()){
            auto [dis_cur, cur]=pq.top();
            pq.pop();
            if(dis_cur>dis2[cur]) continue;

            for(auto [next, cost]:memo[cur]){
                if(dis2[cur]+cost< dis2[next]){
                    dis2[next]=dis2[cur]+cost;
                    pq.emplace(dis2[next], next);
                }
            }
        }

        pq=priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>>{}; // pq 不可以clear
        dis_dest[dest]=0;
        pq.emplace(0, dest);
        while(!pq.empty()){
            auto [dis_cur, cur]=pq.top();
            pq.pop();
            if(dis_cur>dis_dest[cur]) continue;

            for(auto [next, cost]:memo_inv[cur]){
                if(dis_dest[cur]+cost< dis_dest[next]){
                    dis_dest[next]=dis_dest[cur]+cost;
                    pq.emplace(dis_dest[next], next);
                }
            }
        }

        long long ans=MAX;
        ans=min(ans, dis1[dest]+dis2[dest]); // 可能不coincide
        for(int i=0;i<n;i++){
            ans=min(ans, dis1[i]+dis2[i]+dis_dest[i]);
        }
        // for(int i=0;i<n;i++){
        //     cout<<"#"<<i<<":";
        //     cout<<dis1[i]<<','<<dis2[i]<<','<<dis_dest[i]<<endl;
        // }
        if(ans==MAX)
            return -1;
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n[[4,2,20],[4,3,46],[0,1,15],[0,1,43],[0,1,32],[3,1,13]]\n0\n4\n1\n
// @lcpr case=end
// @lcpr case=start
// 6\n[[0,2,2],[0,5,6],[1,0,3],[1,4,5],[2,1,1],[2,3,3],[2,3,4],[3,4,2],[4,5,1]]\n0\n1\n5\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[0,1,1],[2,1,1]]\n0\n1\n2\n
// @lcpr case=end

 */

