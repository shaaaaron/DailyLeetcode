/*
 * @lc app=leetcode.cn id=406 lang=cpp
 * @lcpr version=30122
 *
 * [406] 根据身高重建队列
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
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](auto& x, auto& y){
            return x[0]<y[0] || x[0]==y[0]&&x[1]<y[1];  
        });

        int n=people.size();
        vector<vector<int>> ans(n, vector<int>{-1, -1});

        for(auto &cur: people){
            int h=cur[0], k=cur[1];

            int tmp=k, idx=0;
            while(tmp>=0){
                while(ans[idx][0]!=-1 && ans[idx][0]<h){ // 遍历的时候，每次开头社区不要的元素
                    idx++;
                }

                if(tmp==0)
                    ans[idx]=cur;

                idx++;
                tmp--;
            }
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]\n
// @lcpr case=end

 */

