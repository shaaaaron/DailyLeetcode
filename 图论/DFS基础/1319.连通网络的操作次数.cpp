/*
 * @lc app=leetcode.cn id=1319 lang=cpp
 * @lcpr version=30122
 *
 * [1319] 连通网络的操作次数
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

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
            return -1;
        p.resize(n);
        for(int i=0;i<n;i++)
            p[i]=i;

        for(auto & con:connections){
            merge(con[0], con[1]);
        }
        
        int unions=0;
        for(int i=0;i<n;i++)
            if(p[i]==i)
                unions++;

        return unions-1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n[[0,1],[0,2],[1,2]]\n
// @lcpr case=end

// @lcpr case=start
// 6\n[[0,1],[0,2],[0,3],[1,2],[1,3]]\n
// @lcpr case=end

// @lcpr case=start
// 6\n[[0,1],[0,2],[0,3],[1,2]]\n
// @lcpr case=end

// @lcpr case=start
// 5\n[[0,1],[0,2],[3,4],[2,3]]\n
// @lcpr case=end

 */

