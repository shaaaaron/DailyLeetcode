/*
 * @lc app=leetcode.cn id=2092 lang=cpp
 * @lcpr version=30122
 *
 * [2092] 找出知晓秘密的所有专家
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
#include <map>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<map<int,vector<int>>> memo(n);// 默认从小到大
        //std::map<int, int, std::greater<int>> myMap; 从大到小
        for(auto & meet:meetings){
            int x=meet[0], y=meet[1], t=meet[2];
            memo[x][t].push_back(y);
            memo[y][t].push_back(x);
        }
        
        function<bool(const pair<int,int>, const pair<int,int>)> cmp=[](const pair<int,int> &x, const pair<int,int>& y){ // 如果时引用需要const
            return x.second>y.second;
        };
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp) > pq(cmp); // 时间从小到大
        pq.push({0,0});
        pq.push({firstPerson,0});
        memo[0][0]={}; // 由于后面的find，所以这里需要初始化memo
        memo[firstPerson][0]={};

        vector<int> vis(n);
        // vis[0]=vis[firstPerson]=1;
        // 放到队列还没处理，所以不vis

        while(!pq.empty()){
            int id=pq.top().first, t=pq.top().second;
            pq.pop();
            if(vis[id]) continue;
            vis[id]=1;
            for(auto it=memo[id].find(t); it!=memo[id].end();it++){
                int next_t=it->first;// 迭代器使用
                auto& vec=it->second;
                for(auto next_id:vec){
                    pq.push({next_id, next_t});
                }
            }
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            if(vis[i])
                ans.push_back(i);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 6\n[[1,2,5],[2,3,8],[1,5,10]]\n1\n
// @lcpr case=end

// @lcpr case=start
// 4\n[[3,1,3],[1,2,2],[0,3,3]]\n3\n
// @lcpr case=end

// @lcpr case=start
// 5\n[[3,4,2],[1,2,1],[2,3,1]]\n1\n
// @lcpr case=end

 */

