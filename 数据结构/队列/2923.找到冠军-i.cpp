/*
 * @lc app=leetcode.cn id=2923 lang=cpp
 * @lcpr version=30122
 *
 * [2923] 找到冠军 I
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

    int findChampion(vector<vector<int>>& grid) {
        deque<int> dq;
        for(int i=0;i<grid.size();i++){
            dq.push_back(i);
        }

        while(dq.size()>=2){
            int x=dq.front();
            dq.pop_front();
            int y=dq.front();
            dq.pop_front();

            if( grid[x][y]){
                dq.push_back(x);
            }else{
                dq.push_back(y);
            }
        }
        return dq.back();
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,1],[0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0,1],[1,0,1],[0,0,0]]\n
// @lcpr case=end

 */

