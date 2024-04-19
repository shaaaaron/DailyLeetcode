/*
 * @lc app=leetcode.cn id=90 lang=cpp
 * @lcpr version=30122
 *
 * [90] 子集 II
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
    vector<pair<int,int>> nums;

    vector<int> now;

    vector<vector<int>> ans;

    void bt(int k){
        if(k==nums.size()){
            ans.push_back(now);
            return; // return !
        }

        int val=nums[k].first, val_num=nums[k].second;
        for(int i=0;i<=val_num;i++){
            for(int j=1;j<=i;j++)now.push_back(val);
            bt(k+1);
            for(int j=1;j<=i;j++)now.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i=0,j;
        while(i<nums.size()){
            j=i;
            while(j<nums.size() && nums[j]==nums[i]){
                j++;
            }

            this->nums.push_back(make_pair(nums[i], j-i));
            i=j;
        }

        bt(0);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

