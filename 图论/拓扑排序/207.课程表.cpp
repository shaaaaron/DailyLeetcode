/*
 * @lc app=leetcode.cn id=207 lang=cpp
 * @lcpr version=30122
 *
 * [207] 课程表
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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<set<int>> memo(numCourses);
    
        vector<int> in(numCourses);
        for(auto& eg:prerequisites){
            in[eg[1]]++;
            memo[eg[0]].insert(eg[1]);
        }

        deque<int> dq;
        for(int i=0;i<numCourses;i++){
            if(!in[i])
                dq.push_back(i);
        }

        while(!dq.empty()){
            int cur=dq.front();
            dq.pop_front();
            for(int next:memo[cur]){
                in[next]--;
                if(in[next]==0){
                    dq.push_back(next);
                }
            }
        }

        return count(in.begin(), in.end(), 0)==numCourses;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n[[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[1,0],[0,1]]\n
// @lcpr case=end

 */

