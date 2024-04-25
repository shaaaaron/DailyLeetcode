/*
 * @lc app=leetcode.cn id=841 lang=cpp
 * @lcpr version=30122
 *
 * [841] 钥匙和房间
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
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();

        vector<int> locks(n,1); // 队列中表示可以进入的门，但是还没进入
        locks[0]=0;

        deque<int> dq;
        dq.push_back(0);
        // 队列中表示所有待遍历的，已经遍历的和没有遍历的都不在队列中

        //拓扑排序不需要真的排序，只需要队列记录为0的节点。
        // 而且不是真正的拓扑排序，只能从0开始
        while(!dq.empty()){
            int cur=dq.front(); // 取出当前房间的key
            dq.pop_front();
            for(auto key:rooms[cur]){
                if(locks[key]==1){
                    locks[key]=0;
                    dq.push_back(key);
                }
            }
        }
        bool flag=true;
        for(int lock: locks){
            if(lock){
                flag=false;
            }
        }

        return flag;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1],[2],[3],[]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3],[3,0,1],[2],[0]]\n
// @lcpr case=end

 */

