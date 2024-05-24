/*
 * @lc app=leetcode.cn id=2589 lang=cpp
 * @lcpr version=30201
 *
 * [2589] 完成所有任务的最少时间
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
    int findMinimumTime(vector<vector<int>>& tasks) {
        unordered_set<int> memo;
        int n=tasks.size();
        vector<int> idx(n);
        for(int i=0;i<n;i++) idx[i]=i;

        sort(idx.begin(), idx.end(), [&](int x, int y){
            return tasks[x][1]<tasks[y][1];
        });

        for(int i=0;i<n;i++){
            auto &task=tasks[idx[i]];
            // cout<<task[0]<<":"<<task[1]<<","<<task[2]<<endl;
            for(int j=task[0];j<=task[1];j++){
                if(memo.count(j)){
                    task[2]--;
                }
            }
            for(int j=task[1];j>=task[0] && task[2]>0;j--){
                if(memo.count(j)==0){
                    memo.insert(j);
                    task[2]--;
                }
            }
        }

        return memo.size();
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[2,3,1],[4,5,1],[1,5,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3,2],[2,5,3],[5,6,2]]\n
// @lcpr case=end
// @lcpr case=start
// [[69,84,10],[66,78,6],[75,90,5],[78,79,2]]\n
// @lcpr case=end

 */

