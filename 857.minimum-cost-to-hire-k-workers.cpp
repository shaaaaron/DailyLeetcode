/*
 * @lc app=leetcode.cn id=857 lang=cpp
 * @lcpr version=30122
 *
 * [857] 雇佣 K 名工人的最低成本
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
#include <limits>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
//https://leetcode.cn/problems/minimum-cost-to-hire-k-workers/solutions/1815856/yi-bu-bu-ti-shi-ru-he-si-kao-ci-ti-by-en-1p00/?envType=daily-question&envId=2024-05-02
// 核心是基于w/g和从小到大，而不是从大到小，考虑颠倒顺序
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        double ans=numeric_limits<double>::max();

        vector<int> idx;
        for(int i=0;i<quality.size();i++){
            idx.push_back(i);
        }
        sort(idx.begin(), idx.end(), [&](auto &x, auto& y){
            return wage[x]/double(quality[x])< wage[y]/double(quality[y]);
        });

        priority_queue<int> pq;
        int q_sum=0;
        for(int i=0;i<k;i++){
            pq.push(quality[idx[i]]);
            q_sum+=quality[idx[i]];
        }

        ans=double(q_sum)*wage[idx[k-1]]/double(quality[idx[k-1]]);

        for(int i=k;i<idx.size();i++){
            pq.push(quality[idx[i]]);
            q_sum= q_sum-pq.top()+quality[idx[i]];
            pq.pop();

            ans=min(ans, wage[idx[i]]/double(quality[idx[i]])*(q_sum));
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,20,5]\n[70,50,30]\n2\n
// @lcpr case=end

// @lcpr case=start
// [3,1,10,10,1]\n[4,8,2,2,7]\n3\n
// @lcpr case=end

 */

