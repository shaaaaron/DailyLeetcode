/*
 * @lc app=leetcode.cn id=134 lang=cpp
 * @lcpr version=30122
 *
 * [134] 加油站
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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        deque<pair<int,int>> dq;
        for(int i=0;i<gas.size();i++){
            dq.push_back( make_pair(gas[i]-cost[i], i));
        }        
        
        int waitflag=0;
        while(dq.size()>=2){
            pair<int,int> pr=dq.front();
            dq.pop_front();

            if(pr.first>=0&& pr.first+dq.front().first>=0 ||
                pr.first<=0&&dq.front().first<=0){
                pair<int,int> pr_2=dq.front();
                dq.pop_front();
                // 0y也要放，不然dq直接从2变成0
                dq.push_back( make_pair(pr.first+pr_2.first, pr.second));
                waitflag=0;
            }else{// 如果这种情况，则下一次必然情况1.因此一轮问题缩小一半
                dq.push_back(pr);
                waitflag++;
                if(waitflag==dq.size()) return -1;
            }
            // -+是不能合并的
        }

        //推出了也未必有解
        if(dq.front().first>=0)
            return dq.front().second;
        return -1;
        // 做法是可以的，但是最后一个样例本身有错误
        // @lcpr case=start
        // [2,0,0,0,0,0]\n[0,1,0,0,0,0]\n
        // @lcpr case=end
        // 但是答案只能0
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,0,0,0,0,0]\n[0,1,0,0,0,0]\n
// @lcpr case=end


// @lcpr case=start
// [2,3,4]\n[3,4,3]\n
// @lcpr case=end
// @lcpr case=start
// [1,2,3,4,5]\n[3,4,5,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4]\n[3,4,3]\n
// @lcpr case=end

 */

