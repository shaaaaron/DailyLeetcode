/*
 * @lc app=leetcode.cn id=621 lang=cpp
 * @lcpr version=30122
 *
 * [621] 任务调度器
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
// 注意，这题和 装满杯子需要的最短总时长 的题目非常像，所以觉得下面的做法是正确的
    int leastInterval(vector<char>& tasks, int n) {
        auto cmp=[](auto &x, auto& y){ //优先队列是greater
            return x.second<y.second;
        };
        priority_queue<pair<char,int>, vector<pair<char,int>>, decltype(cmp)> pq(cmp); // less降序队列，greater升序队列
        //  decltype(cmp) 不是尖括号

        int memo[30];
        for(auto ch:tasks){
            memo[ch-'A']++;
        }

        for(int i=0;i<26;i++){
            if(memo[i]>0){
                pq.push({'A'+i, memo[i]});
            }
        }

        int ans=0;
        while(!pq.empty()){
            cout<<pq.size()<<endl;
            vector<pair<char,int> > tmp; //一个回合只能一次，暂存一下

            int pq_size=pq.size();
            int i;
            for(i=0;i<pq_size&&i<n+1;i++){ // 为n的冷却时间，所以一个周期是n+1
                auto pr=pq.top();
                pq.pop();
                pr.second--;
                if(pr.second){
                    tmp.push_back(pr);
                }
            }

            for(auto pr:tmp){
                pq.push(pr);
            }

            if(!pq.size()){ //最后一个周期算完了
                            // 太傻逼了，非清楚到底是为0还是不为0
                ans+=i;
            }else{
                ans+=n+1;
            }
            cout<<ans<<endl;
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["A","A","A","B","B","B"]\n2\n
// @lcpr case=end

// @lcpr case=start
// ["A","A","A","B","B","B"]\n0\n
// @lcpr case=end

// @lcpr case=start
// ["A","A","A","A","A","A","B","C","D","E","F","G"]\n2\n
// @lcpr case=end

 */

