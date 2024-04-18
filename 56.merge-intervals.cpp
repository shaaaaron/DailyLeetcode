/*
 * @lc app=leetcode.cn id=56 lang=cpp
 * @lcpr version=30122
 *
 * [56] 合并区间
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

// 也是从恰好重叠到一个点的情况来看，则从左边区间，连续的向右边合并
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &x, auto &y){
            return x[0]<y[0];
        });

        int left=intervals[0][0];
        int right=intervals[0][1];
        vector<vector<int>>  ans;

        for(int i=0;i<intervals.size();i++){
            auto &inter=intervals[i];
            if(right<inter[0]){
                ans.push_back(vector<int>{left, right});
                left=inter[0];
                right=inter[1];
            }else{
                right=max(right, inter[1]);
            }

            if(i==intervals.size()-1){ // 最后补一个
                ans.push_back(vector<int>{left, right});
            }
        }// 其实上面整段也可以换成双指针。补一个/双指针 
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,3],[2,6],[8,10],[15,18]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,4],[4,5]]\n
// @lcpr case=end

 */

