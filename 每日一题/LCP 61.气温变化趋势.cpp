/*
 * @lc app=leetcode.cn id=LCP 61 lang=cpp
 * @lcpr version=30204
 *
 * [LCP 61] 气温变化趋势
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
    int temperatureTrend(vector<int>& temperatureA, vector<int>& temperatureB) {
        int ans=0, tmp=0;
        for(int i=1;i<temperatureA.size();i++){
            if(temperatureA[i]>temperatureA[i-1]&&temperatureB[i]>temperatureB[i-1]
            ||temperatureA[i]<temperatureA[i-1]&&temperatureB[i]<temperatureB[i-1]
            ||temperatureA[i]==temperatureA[i-1]&&temperatureB[i]==temperatureB[i-1]){
                tmp++;
                ans=max(ans,tmp);
            }else{
                tmp=0;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [21,18,18,18\n[34,32,16,16,17]`>\n
// @lcpr case=end

// @lcpr case=start
// [5,10,16,-6,15,11\n[16,22,23,23,25,3,-16]`>\n
// @lcpr case=end

 */

