/*
 * @lc app=leetcode.cn id=1310 lang=cpp
 * @lcpr version=30122
 *
 * [1310] 子数组异或查询
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
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int> xors(n+1);
        xors.push_back(0);

        for(int i=0;i<arr.size();i++){
            xors[i+1]=xors[i]^arr[i];
        }

        vector<int> ans;
        for(auto & tmp: queries){
            ans.push_back(xors[tmp[1]+1]^xors[tmp[0]]);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,4,8]\n[[0,1],[1,2],[0,3],[3,3]]\n
// @lcpr case=end

// @lcpr case=start
// [4,8,2,10]\n[[2,3],[1,3],[0,0],[0,3]]\n
// @lcpr case=end

 */

