/*
 * @lc app=leetcode.cn id=2038 lang=cpp
 * @lcpr version=30122
 *
 * [2038] 如果相邻两个颜色均相同则删除当前颜色
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
    bool winnerOfGame(string colors) {
        queue<pair<char,int>> q;
        int n=colors.size();
        int i=0,j;
        while(i<n){
            j=i;
            while(j<n && colors[j]==colors[i]){ // ==!
                j++;
            }
            q.push(make_pair(colors[i], j-i));
        }

        char ch='A';
        while(!q.empty()){
            int qsize=q.size();
            int i=0;
            while(i<qsize){
                int j=i;
            }
        }
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// "AAABABB"\n
// @lcpr case=end

// @lcpr case=start
// "AA"\n
// @lcpr case=end

// @lcpr case=start
// "ABBBBBBBAAA"\n
// @lcpr case=end

 */

