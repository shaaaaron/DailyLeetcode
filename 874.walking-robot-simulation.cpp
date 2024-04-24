/*
 * @lc app=leetcode.cn id=874 lang=cpp
 * @lcpr version=30122
 *
 * [874] 模拟行走机器人
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
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int,unordered_map<int,int> > memo; // 使用嵌套memo，而不是元组作为key的memo
        // 这么写比较好

        for(auto& obstacle:obstacles){
            int x=obstacle[0], y=obstacle[1];
            if(memo.find(x)==memo.end()){
                memo[x]=unordered_map<int,int>{};
            }

            memo[x][y]=1; // 表示障碍物
        }

        int ans=0;
        int dir=0, x=0, y=0;
        // 0123 表示北东南西，
        vector<pair<int,int>> directions{  {0,1}, {1,0}, {0,-1}, {-1,0}};

        for(int com:commands){
            if(com>=1){
                int dx=directions[dir].first, dy=directions[dir].second;

                int i=1;
                for(i=1;i<=com;i++){
                    if( memo.find(x+dx)!=memo.end() &&
                        memo[x+dx].find(y+dy)!=memo[x+dx].end() &&
                        memo[x+dx][y+dy]==1){
                        break;
                    }
                    x+=dx;
                    y+=dy;
                    ans=max(ans, x*x+y*y);
                }

            }else if(com ==-1){
                dir=(dir+1)%4;
            }else{
                dir=(dir+3)%4;
            }
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,-1,3]\n[]\n
// @lcpr case=end

// @lcpr case=start
// [4,-1,4,-2,4]\n[[2,4]]\n
// @lcpr case=end

// @lcpr case=start
// [6,-1,-1,6]\n[]\n
// @lcpr case=end

 */

