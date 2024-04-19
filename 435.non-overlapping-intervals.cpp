/*
 * @lc app=leetcode.cn id=435 lang=cpp
 * @lcpr version=30122
 *
 * [435] 无重叠区间
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

// 下面是一个简单的思考过程
// 最理想的情况是不重叠。先来思考复杂一点的情况，只在一个点重叠。应该去掉左右“影响最大”的区间，留下最小的
// 但是区间有的左边大，有的右边大，什么才是影响大？
// 从左到右，第一个遇到问题的，左边没有问题，只看右边！

// 也就是只按区间的左端点进行排序，然后看哪个区间对右边的影响大
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans=0;
        sort(intervals.begin(), intervals.end(),[](auto &x, auto &y){
            return x[0]<y[0];
        });

        int min_loc=INT_MIN; // 数据范围
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]>=min_loc){
                min_loc=intervals[i][1];
            }else{ // 出现了重叠
                ans++;
                min_loc=min(min_loc, intervals[i][1]);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2],[2,3],[3,4],[1,3]]\n
// @lcpr case=end

// @lcpr case=start
// [ [1,2], [1,2], [1,2] ]\n
// @lcpr case=end

// @lcpr case=start
// [ [1,2], [2,3] ]\n
// @lcpr case=end

 */

