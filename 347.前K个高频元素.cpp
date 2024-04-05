/*
 * @lc app=leetcode.cn id=347 lang=cpp
 * @lcpr version=30121
 *
 * [347] 前 K 个高频元素
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
// 可以使用map，但是优先队列略微减少时间开销
// python dict和C++ unordered_map的用法，unordered_map内部有冲突解决地址，不需要自己处理hash冲突
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> memo;
        for(int i=0;i<nums.size();i++){
            if(memo.find(nums[i])== memo.end()){//
                memo[nums[i]]=1;
            }else{
                memo[nums[i]]++; // 可以直接++,因为会默认初始化为0
            }
        }

        vector<tuple<int,int>> tmp;
        // 迭代器可以迭代k
        for(auto & pair:memo){//遍历memo，而不是遍历数组
            tmp.push_back(tuple<int,int>(pair.first, pair.second)); // pair
            // cout<<pair.first<<","<<pair.second<<endl;
        }
        sort(tmp.begin(), tmp.end(), [](tuple<int,int>&a, tuple<int,int>&b){
            return get<1>(a) > get<1>(b);// 排序可以省略返回值
        });//不需要赋值

        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(get<0>(tmp[i]));
        }
        return ans;

        // priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que; 定义元素类型，底层容器，比较函数


        // class mycomparison {
        // public:
        //     bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
        //         return lhs.second > rhs.second;
        //     }
        // };
        // left小于right从小到大排序，小顶堆
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1,2,2,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */

