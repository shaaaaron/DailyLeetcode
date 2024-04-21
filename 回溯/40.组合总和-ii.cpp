/*
 * @lc app=leetcode.cn id=40 lang=cpp
 * @lcpr version=30122
 *
 * [40] 组合总和 II
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
// 五要素
    vector<pair<int,int>> convert_can;
    int target;

    vector<int> now;
    int nowsum;// 只是为了快速计算

    vector<vector<int>> ans;

    // 有两种bt方式，一种是bt下一个数，一种是bt当前的有几个
    void bt(int k){// 当前可使用的第一个物体的索引
        if(nowsum==target){ // 放在出界的前面
            ans.push_back(now);
            return;
        }
        if(nowsum>target) return ;

        if(k>=convert_can.size())return ;

        for(int i=0;i<=convert_can[k].second;i++){ // =
            for(int j=1;j<=i;j++) now.push_back(convert_can[k].first); //由于是计数，是从1开始而不是0
            nowsum += i*convert_can[k].first;
            bt(k+1);
            for(int j=1;j<=i;j++) now.pop_back();
            nowsum -= i*convert_can[k].first;
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        this->target=target;

        int i=0,j=0;
        while(i<candidates.size()){
            while(j<candidates.size() && candidates[j]==candidates[i]){
                j++;
            }
            
            // 物品价值是can[i]，实际数量是j-i个
            convert_can.push_back(make_pair(candidates[i], j-i)); //剩余为k

            i=j;
        }// 由于重复，所以进行去重
        nowsum=0;
        
        // 多重背包用二进制优化仍然会重复
        // 使用bt更好些
        bt(0);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,1,2,7,6,1,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2,5,2,1,2]\n5\n
// @lcpr case=end

 */

