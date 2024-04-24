/*
 * @lc app=leetcode.cn id=419 lang=cpp
 * @lcpr version=30122
 *
 * [419] 甲板上的战舰
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
    int countBattleships(vector<vector<char>>& board) {
        int m=board.size(), n=board[0].size();
        int ans=0;

        for(int i=0;i<m;i++){
            int start=0, end=0;
            while(start<n){
                if(board[i][start]=='.') {
                    start++;
                    continue;
                }

                end=start;
                while(end<n && board[i][end]=='X'){
                    end++;
                }
                end--;

                // [start, end]
                if(start<end){// 识别船只的两种状态
                    ans++;
                }else{
                    if(i==0 || board[i-1][start]=='.')
                        ans++;
                }

                start=end+1; // 区间的写法，记得用end更新，不能start++
            }
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]\n
// @lcpr case=end

// @lcpr case=start
// [["."]]\n
// @lcpr case=end

 */

