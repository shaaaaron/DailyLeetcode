/*
 * @lc app=leetcode.cn id=216 lang=cpp
 * @lcpr version=30122
 *
 * [216] 组合总和 III
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

// 相比于组合总和2添加了对`k个数的限制`

class Solution {
public:
    vector<int> now;
    int nowsum;

    vector<vector<int>> ans;
    int k,n;
    void bt(int next_num){
        if(now.size()==k){ // 长度递归终止条件
            if(nowsum==n){
                ans.push_back(now);
            }
            return;
        }

        if(nowsum>n) return; // 总和过大，注意不能等于
        if(nowsum+(next_num+9)*(10-next_num)/2<n) return; // 总和过小

        for(int i=next_num;i<=9;i++){
            now.push_back(i);
            nowsum+=i;
            bt(i+1);
            now.pop_back();
            nowsum-=i;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        this->k=k;
        this->n=n;
        
        nowsum=0;
        
        bt(1);  // 下一个可以选用的数字
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n7\n
// @lcpr case=end

// @lcpr case=start
// 3\n9\n
// @lcpr case=end

// @lcpr case=start
// 4\n1\n
// @lcpr case=end

 */

