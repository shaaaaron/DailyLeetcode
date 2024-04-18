/*
 * @lc app=leetcode.cn id=452 lang=cpp
 * @lcpr version=30122
 *
 * [452] 用最少数量的箭引爆气球
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
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](auto &x, auto &y){
            // return x[0]<y[0] || x[0]==y[0]&&x[1]<y[1];
            return x[1]<y[1]; // 根据右端点判断第一次开始开枪的时机
        });

        int ans=0;
        bool first=true;
        int max_loc;// 看数据范围，不能intmin，额外flag

        for(int i=0;i<points.size();i++){
            if(first || max_loc<points[i][0]){
                first=false;
                ans++;
                max_loc=points[i][1];
            }
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
[[9,12],[1,10],[4,11],[8,12],[3,9],[6,9],[6,7]]
// @lcpr case=end
// @lcpr case=start
// [[10,16],[2,8],[1,6],[7,12]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[3,4],[5,6],[7,8]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[2,3],[3,4],[4,5]]\n
// @lcpr case=end

 */

