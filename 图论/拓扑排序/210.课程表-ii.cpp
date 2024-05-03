/*
 * @lc app=leetcode.cn id=210 lang=cpp
 * @lcpr version=30122
 *
 * [210] 课程表 II
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
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<set<int>> memo(numCourses);
        vector<int> in(numCourses);
        for(auto &eg:prerequisites){
            memo[eg[1]].insert(eg[0]);
            in[eg[0]]++;
        }

        vector<int> ans;
        deque<int> dq;
        for(int i=0;i<numCourses;i++)
            if(in[i]==0){
                dq.push_back(i);
                ans.push_back(i);
            }


        while(!dq.empty()){
            int cur=dq.front();
            dq.pop_front();
            for(int next:memo[cur]){
                in[next]--;
                if(!in[next]){
                    dq.push_back(next);
                    ans.push_back(next);
                }
            }
        }

        if(ans.size()==numCourses)
            return ans;
        return {};
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n[[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[[1,0],[2,0],[3,1],[3,2]]\n
// @lcpr case=end

// @lcpr case=start
// 1\n[]\n
// @lcpr case=end

 */

