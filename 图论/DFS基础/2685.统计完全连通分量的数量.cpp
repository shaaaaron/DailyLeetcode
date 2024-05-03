/*
 * @lc app=leetcode.cn id=2685 lang=cpp
 * @lcpr version=30122
 *
 * [2685] 统计完全连通分量的数量
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
    vector<int> p;
    int find(int x){
        if(x==p[x])return x;
        return p[x]=find(p[x]);
    }

    void merge(int x, int y){
        p[find(x)]=find(y);
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        p.resize(n);
        for(int i=0;i<n;i++)
            p[i]=i;

        for(auto & eg:edges){
            merge(eg[0], eg[1]);
        }

        int union_num=0;
        for(int i=0;i<n;i++){
            if(find(i)==i)
                union_num++;
        }
                
        vector<int> node(n), edge(n);
        for(int i=0;i<n;i++){
            node[p[i]]++;
        }
        for(auto & eg:edges){
            edge[p[eg[0]]]++;
        }

        int ans=0;
        for(int i=0;i<n;i++){
            if(i!=p[i]) continue;
            if(node[i]*(node[i]-1)/2==edge[i])
            // if(edge.find(i)!=edge.end() && node[i]*(node[i]-1)/2==edge[i])
                ans++;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 6\n[[0,1],[0,2],[1,2],[3,4]]\n
// @lcpr case=end

// @lcpr case=start
// 6\n[[0,1],[0,2],[1,2],[3,4],[3,5]]\n
// @lcpr case=end

 */

