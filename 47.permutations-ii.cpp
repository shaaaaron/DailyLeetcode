/*
 * @lc app=leetcode.cn id=47 lang=cpp
 * @lcpr version=30122
 *
 * [47] 全排列 II
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

    // 对于组合去重，首先观察什么时候出现重复，然后避免情况发生
    // 让相同数字每次从前向后的顺序选取
    vector<int> nums;
    vector<bool> visited;

    vector<int> now;

    vector<vector<int>> ans;

    void bt(){
        if(now.size()==nums.size()){
            ans.push_back(now);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(visited[i]) continue;
            // bool conflict=false;

            // for(int j=0;j<i;j++){
            //     if(nums[j]==nums[i] && visited[j]==false){
            //         conflict=true;
            //         break;
            //     }
            // }
            // if(conflict) continue;
            if(i>=1 && nums[i-1]==nums[i] && !visited[i-1]) continue;// 不需要之前的，只需要for循环前一个

            now.push_back(nums[i]);
            visited[i]=true;
            bt();
            visited[i]=false;
            now.pop_back();
        }


    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        this->nums=nums;
        visited.resize(nums.size());
        for(int i=0;i<visited.size();i++){
            visited[i]=false;
        }

        bt();
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */

