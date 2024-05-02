/*
 * @lc app=leetcode.cn id=547 lang=cpp
 * @lcpr version=30122
 *
 * [547] 省份数量
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
    vector<int> father;

    int find(int n){
        if(n==father[n]) return n;
        return father[n]=find(father[n]);
    }

    void merge(int x, int y){
        father[find(x)]=find(y);
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        father.resize(n);
        for(int i=0;i<n;i++){
            father[i]=i;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j]){
                    merge(i,j);
                }
            }
        }

        int ans=0;
        for(int i=0;i<n;i++){
            if(father[i]==i)
                ans++;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,1,0],[1,1,0],[0,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,0],[0,1,0],[0,0,1]]\n
// @lcpr case=end

 */

