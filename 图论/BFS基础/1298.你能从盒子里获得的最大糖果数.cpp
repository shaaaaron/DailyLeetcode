/*
 * @lc app=leetcode.cn id=1298 lang=cpp
 * @lcpr version=30122
 *
 * [1298] 你能从盒子里获得的最大糖果数
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
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n=status.size();
        vector<pair<int,int>> ok_box(n, {0,0}); // 表示不能接触到盒子/有锁
        for(int i=0;i<n;i++){
            if(status[i])
                ok_box[i].second=1;
        }

        vector<int> vis(n);
        deque<int> dq;
        for(int i:initialBoxes){
            ok_box[i].first=1;
        }
        for(int i=0;i<n;i++){
            if(ok_box[i]==make_pair(1,1)){//
                vis[i]=1;
                dq.push_back(i);
            }
        }
        
        while(!dq.empty()){
            int cur=dq.front();
            dq.pop_front();
            for(int next:keys[cur]){
                if(vis[next]) continue;
                ok_box[next].second=1;
                // pair支持比较是否相等
                if(ok_box[next]==make_pair(1,1)){//
                    vis[next]=1;
                    dq.push_back(next);
                }
            }
            for(int next:containedBoxes[cur]){
                if(vis[next]) continue;
                ok_box[next].first=1;
                if(ok_box[next]==make_pair(1,1)){
                    vis[next]=1;
                    dq.push_back(next);
                }
            }
        }

        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i])
                ans+=candies[i];
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,0,1,0]\n[7,5,4,100]\n[[],[],[],[]]\n[[1,2],[3],[],[]]\n[1,2]\n
// @lcpr case=end
// @lcpr case=start
// [1,0,1,0]\n[7,5,4,100]\n[[],[],[1],[]]\n[[1,2],[3],[],[]]\n[0]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,0,0,0,0]\n[1,1,1,1,1,1]\n[[1,2,3,4,5],[],[],[],[],[]]\n[[1,2,3,4,5],[],[],[],[],[]]\n[0]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1]\n[100,1,100]\n[[],[0,2],[]]\n[[],[],[]]\n[1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n[100]\n[[]]\n[[]]\n[]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1]\n[2,3,2]\n[[],[],[]]\n[[],[],[]]\n[2,1,0]\n
// @lcpr case=end

 */

