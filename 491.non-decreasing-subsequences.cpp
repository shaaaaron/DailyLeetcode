/*
 * @lc app=leetcode.cn id=491 lang=cpp
 * @lcpr version=30122
 *
 * [491] 非递减子序列
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
    vector<int> nums;

    vector<int> now;
    // int last;

    vector<vector<int>> ans;

    void bt(int k){
        if(k==nums.size()){ // 对每个数字选择加或者不加？
            if(now.size()>=2)ans.push_back(now);
            return;
        }

        // 如果不选了，就一直不选。没法写
        // 如果选了，就一直选
        // 这里很重要

        // 区别在于第一种情况是否执行，leetcode里面由于last比较好写。我这没有比较特殊.
        // 下面也可以拆分
        if(now.size()!=0 && now[now.size()-1] ==nums[k]){
            now.push_back(nums[k]);
            bt(k+1);
            now.pop_back();
        }else{
            bt(k+1);
            
            if(now.size()==0 || now[now.size()-1] <=nums[k]){
                now.push_back(nums[k]);
                bt(k+1);
                now.pop_back();
            }
        }

    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        // sort(nums.begin(), nums.end()); //笑死，为什么排序
        // 由于考虑组合数，所以将相同val聚合在一起
        // https://leetcode.cn/problems/non-decreasing-subsequences/solutions/387656/di-zeng-zi-xu-lie-by-leetcode-solution/ 关于去重有一个清晰的认识

        this->nums=nums;
        bt(0);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,1,1,1]\n
// @lcpr case=end
// @lcpr case=start
// [4,6,7,7]\n
// @lcpr case=end

// @lcpr case=start
// [4,4,3,2,1]\n
// @lcpr case=end

 */

