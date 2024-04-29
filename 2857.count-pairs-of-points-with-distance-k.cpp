/*
 * @lc app=leetcode.cn id=2857 lang=cpp
 * @lcpr version=30122
 *
 * [2857] 统计距离为 k 的点对
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
    int countPairs(vector<vector<int>>& coordinates, int k) {
        unordered_map<int, unordered_map<int,int>> memo;
        int ans=0;
        for(auto&vec: coordinates){
            int x=vec[0], y=vec[1];
            for(int i=0;i<=k;i++){
                if(memo.find(i^x)!=memo.end() && memo[i^x].find((k-i)^y)!=memo[i^x].end()){
                    ans+=memo[i^x][(k-i)^y]; // 使用对应memo的end
                }

                if(memo.find(i^x)==memo.end()){ // 初始化，q
                    memo[i^x]=unordered_map<int,int>{};
                }
            }
            memo[x][y]++; // 记录自己，寻找互补 // 只补一次
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2],[4,2],[1,3],[5,2]]\n5\n
// @lcpr case=end

// @lcpr case=start
// [[1,3],[1,3],[1,3],[1,3],[1,3]]\n0\n
// @lcpr case=end

 */

