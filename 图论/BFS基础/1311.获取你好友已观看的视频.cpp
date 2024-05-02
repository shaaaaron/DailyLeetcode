/*
 * @lc app=leetcode.cn id=1311 lang=cpp
 * @lcpr version=30122
 *
 * [1311] 获取你好友已观看的视频
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
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n=watchedVideos.size();

        deque<int> dq;
        vector<int> vis(n);
        dq.push_back(id);
        vis[id]=1;

        for(int i=1;i<=level;i++){
            int dq_size=dq.size();
            for(int i=0;i<dq_size;i++){
                int cur=dq.front();
                dq.pop_front();

                for(int next:friends[cur]){
                    if(vis[next]==0){
                        dq.push_back(next);
                        vis[next]=1;
                    }
                }
            }
        }

        unordered_map<string,int> memo;
        while(!dq.empty()){
            int cur=dq.front();
            dq.pop_front();
            for(auto str:watchedVideos[cur]){
                memo[str]++;
            }
        }

        vector<string> ans;
        for(auto & pr:memo){
            ans.push_back(pr.first);
        }
        sort(ans.begin(), ans.end(), [&](auto &x, auto &y){
            return memo[x]<memo[y] || memo[x]==memo[y]&&x<y;
        });
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [["A","B"],["C"],["B","C"],["D"]]\n[[1,2],[0,3],[0,3],[1,2]]\n0\n1\n
// @lcpr case=end

// @lcpr case=start
// [["A","B"],["C"],["B","C"],["D"]]\n[[1,2],[0,3],[0,3],[1,2]]\n0\n2\n
// @lcpr case=end

 */

