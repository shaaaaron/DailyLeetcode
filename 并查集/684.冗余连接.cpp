/*
 * @lc app=leetcode.cn id=684 lang=cpp
 * @lcpr version=30122
 *
 * [684] 冗余连接
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
        if(p[x]==x) return x;

        p[x]=find(p[x]);
        return p[x];
    
    }

    void merge(int x, int y){
        p[find(x)]=p[find(y)];
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();

        p.resize(n+1);  // 1到n是可用的
        for(int i=1;i<=n;i++)   p[i]=i;

        for(auto &edge:edges){
            int x=edge[0], y=edge[1];
            if(find(x)==find(y)) return edge;
            else    merge(x, y);
        }

        return vector<int>{-1,-1};
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2], [1,3], [2,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2], [2,3], [3,4], [1,4], [1,5]]\n
// @lcpr case=end

 */

