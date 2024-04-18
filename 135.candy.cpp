/*
 * @lc app=leetcode.cn id=135 lang=cpp
 * @lcpr version=30122
 *
 * [135] 分发糖果
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
// 严格弱序（Strict Weak Ordering）
// 排序算法通常要求提供的比较函数必须满足严格弱序的要求，这意味着比较函数 comp(a, b) 必须满足以下几个条件：

// 非自反性：对于所有 a，comp(a, a) 必须为 false。
// 非对称性：如果 comp(a, b) 为 true，则 comp(b, a) 必须为 false。
// 传递性：如果 comp(a, b) 和 comp(b, c) 都为 true，那么 comp(a, c) 也必须为 true。

// 使用 <= 可能违反了非自反性和非对称性：
// 非自反性：a <= a 是 true，这违反了非自反性。
// 非对称性：如果 a <= b 和 b <= a 同时为 true（例如 a 和 b 相等时），这违反了非对称性。

// 当比较函数违反这些规则时，排序算法可能会出现逻辑混乱，例如：
// 进行错误的元素交换。
// 重复访问同一内存位置或访问非法内存位置。
// 在内部循环中导致死锁或无限循环。

// 另一个做法是贪心，
    int candy(vector<int>& ratings) {
        vector<int> candies;
        vector<pair<int,int>>  a;

        candies.resize(ratings.size()); // 默认是0
        
        for(int i=0;i<ratings.size();i++){
            a.push_back( make_pair(i, ratings[i]) );
        }
        sort(a.begin(), a.end(), [](auto &x, auto& y){ //函数参
            return x.second<y.second; // 必须是严格的,否则堆错误
        });
        
        // 每个人至少一个糖果
        for(auto &pr: a){
            int idx=pr.first;

            int candy=1;
            if(idx>=1 && ratings[idx]>ratings[idx-1]){
                candy=max(candy, candies[idx-1]+1);
            }
            if(idx<ratings.size()-1 && ratings[idx]>ratings[idx+1]){
                candy=max(candy, candies[idx+1]+1);
            }

            candies[idx]=candy;
        }

        int ans=0;
        for(auto& num:candies) ans+=num;
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,5,4,3,2,1,4,3,2,1,3,2,1,1,2,3,4,4,3,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2]\n
// @lcpr case=end

 */

