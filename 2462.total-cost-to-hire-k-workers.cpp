/*
 * @lc app=leetcode.cn id=2462 lang=cpp
 * @lcpr version=30122
 *
 * [2462] 雇佣 K 位工人的总代价
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
// 单纯模拟
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n=costs.size();
        long long ans=0;

        priority_queue<int,vector<int>, greater<int>> q1, q2; // 默认大顶，指定小顶
        deque<int> dq;
        if(1+2*candidates<=n){
            for(int i=0;i<candidates;i++){
                q1.push(costs[i]);
            }
            for(int i=n-1;i>=n-candidates;i--){
                q2.push(costs[i]);
            }
            for(int i=candidates;i<n-candidates;i++){
                dq.push_back(costs[i]);
            }
            while(k&&dq.size()){
                if(q1.top()<=q2.top()){
                    ans+=q1.top();
                    q1.pop();
                    q1.push(dq.front());
                    dq.pop_front();
                }else{
                    ans+=q2.top();
                    q2.pop();
                    q2.push(dq.back());
                    dq.pop_back();
                }
                k--;
            }
            if(k==0) return ans;
        }else{//如果不够，直接补足
            for(int num:costs){
                q1.push(num);
            }
        }

        // 复用下面的代码
        while(!q2.empty()){
            q1.push(q2.top());
            q2.pop();
        }
        while(k){
            ans+=q1.top();
            q1.pop();
            k--;
        }
        return ans;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [17,12,10,2,7,2,11,20,8]\n3\n4\n
// @lcpr case=end

// @lcpr case=start
// [1,2,4,1]\n3\n3\n
// @lcpr case=end

 */

