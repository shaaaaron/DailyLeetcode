/*
 * @lc app=leetcode.cn id=1971 lang=cpp
 * @lcpr version=30122
 *
 * [1971] 寻找图中是否存在路径
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
        if(x==p[x]) return x;
        return p[x]=find(p[x]);
    }

    void merge(int x,int y){
        p[find(x)]=find(y);
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        p.resize(n);
        for(int i=0;i<n;i++){
            p[i]=i;
        }

        for(auto& ed:edges){
            merge(ed[0],  ed[1]);
        }
        
        return find(source)==find(destination);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 10\n[[2,9],[7,8],[5,9],[7,2],[3,8],[2,8],[1,6],[3,0],[7,0],[8,5]]\n1\n0\n
// @lcpr case=end
// @lcpr case=start
// 3\n[[0,1],[1,2],[2,0]]\n0\n2\n
// @lcpr case=end

// @lcpr case=start
// 6\n[[0,1],[0,2],[3,5],[5,4],[4,3]]\n0\n5\n
// @lcpr case=end

 */

