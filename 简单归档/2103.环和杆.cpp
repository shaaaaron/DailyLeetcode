/*
 * @lc app=leetcode.cn id=2103 lang=cpp
 * @lcpr version=30122
 *
 * [2103] 环和杆
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
    int countPoints(string rings) {
        vector<vector<bool>> memo(10, vector<bool>(3)); // 需要指定二维的大小
        for(int i=0;i<rings.size();i+=2){ // 每次增加2
            if(rings[i]=='R'){
                memo[rings[i+1]-'0'][0]=true;
            }else if(rings[i]=='G'){
                memo[rings[i+1]-'0'][1]=true;
            }else{
                memo[rings[i+1]-'0'][2]=true;
            }
        }

        return count(memo.begin(), memo.end(), vector<bool>{true,true,true});
    }
};
// @lc code=end



/*
// @lcpr case=start
// "B0B6G0R6R0R6G9"\n
// @lcpr case=end

// @lcpr case=start
// "B0R0G0R9R0B0G0"\n
// @lcpr case=end

// @lcpr case=start
// "G4"\n
// @lcpr case=end

 */

