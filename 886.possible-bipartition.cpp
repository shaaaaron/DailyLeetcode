/*
 * @lc app=leetcode.cn id=886 lang=cpp
 * @lcpr version=30202
 *
 * [886] 可能的二分法
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
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<set<int>> memo(n+1);
        for(auto & vec:dislikes){
            memo[vec[0]].insert(vec[1]);
            memo[vec[1]].insert(vec[0]);
        }

        vector<int> color(n+1); // 人物编号从1开始
        // 使用广度优先搜索
        deque<int> dq;
        // 有可能不是一个连通分支，BFS写法要遍历所有的连通分支
        for(int i=1;i<=n;i++){
            if(color[i]!=0)
                continue;
            color[i]=1; //12是两个队伍，0表示还没有分
            dq.push_back(i);        
            while(!dq.empty()){
                int now=dq.front();
                dq.pop_front();
                for(int next:memo[now]){
                    if(color[next]==0){
                        color[next]=3-color[now];
                        dq.emplace_back(next);
                    }else if(color[next]==color[now]){
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n[[1,2],[1,3],[2,4]]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[1,2],[1,3],[2,3]]\n
// @lcpr case=end

// @lcpr case=start
// 5\n[[1,2],[2,3],[3,4],[4,5],[1,5]]\n
// @lcpr case=end

 */

