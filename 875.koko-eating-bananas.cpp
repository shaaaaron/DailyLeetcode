/*
 * @lc app=leetcode.cn id=875 lang=cpp
 * @lcpr version=30122
 *
 * [875] 爱吃香蕉的珂珂
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
    int minEatingSpeed(vector<int>& piles, int h) {
        int lt=1, rt=1000*1000*1000;
        while(lt<=rt){
            int md=lt+(rt-lt)/2; // 二分答案防止越界
            long long time=0; // 虽然结果变量不越界，但是中间可能越界
            for(int pile:piles){
                time+=(pile-1)/md+1;
            }

            if(h<time){ // 有一丁点不一样，想一下
                lt=md+1;
            }else{
                rt=md-1;
            }
        }

        return lt;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [805306368,805306368,805306368]\n1000000000\n
// @lcpr case=end
// @lcpr case=start
// [3,6,7,11]\n8\n
// @lcpr case=end

// @lcpr case=start
// [30,11,23,4,20]\n5\n
// @lcpr case=end

// @lcpr case=start
// [30,11,23,4,20]\n6\n
// @lcpr case=end

 */

