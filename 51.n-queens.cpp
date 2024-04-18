/*
 * @lc app=leetcode.cn id=51 lang=cpp
 * @lcpr version=30122
 *
 * [51] N 皇后
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
    int n;

    vector<int> queen;
    vector<string> now;

    vector<vector<string>> ans;

    void bt(){
        if(queen.size()==n){
            ans.push_back(now);
        }

        for(int i=0;i<n;i++){
            bool conflict = false;
            for(int j=0;j<queen.size();j++){ // j,q[j]和 q.size(),i
                int jx=j, jy=queen[j];
                int ix=queen.size(), iy=i;

                if(iy==jy || abs(iy-jy)==ix-jx){
                    conflict=true;
                    break; // break和continue 分清楚
                }
            }
            if(conflict) continue;

            queen.push_back(i);
            now.push_back(string(i, '.')+"Q"+string(n-1-i, '.')); // 字符而不能是字符串
            bt();
            queen.pop_back();
            now.pop_back();
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        this->n=n;
        bt();
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

