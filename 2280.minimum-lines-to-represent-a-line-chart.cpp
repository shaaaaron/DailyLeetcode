/*
 * @lc app=leetcode.cn id=2280 lang=cpp
 * @lcpr version=30122
 *
 * [2280] 表示一个折线图的最少线段数
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
// 使用int乘法而不是浮点数除法表示斜率是否相等
    int minimumLines(vector<vector<int>>& stockPrices) {
        sort(stockPrices.begin(), stockPrices.end(),[](auto& x, auto& y){
            return x[0]<y[0];
        });

        int dx=-1, dy=-1, n=stockPrices.size();
        int lt=0, rt=0;
        int sum=0;
        while(lt<n){
            rt=lt+1;
            while(rt<n){
                if(rt==lt+1){
                    dx=stockPrices[rt][0]-stockPrices[lt][0];
                    dy=stockPrices[rt][1]-stockPrices[lt][1];
                }else{
                    int cur_dx=stockPrices[rt][0]-stockPrices[lt][0];
                    int cur_dy=stockPrices[rt][1]-stockPrices[lt][1];
                    if((long long)dx*cur_dy!=(long long)dy*cur_dx) break;
                    // 注意乘法防止溢出，使用longlong
                }
                rt++;
            }
            
            if(rt-lt>=2){// 如果当前是一个有效的区间，则下一个从rt-1开始
                sum++;
                lt=rt-1;
            }else{// 否则从rt开始，其实就为了越界n退出
                lt=rt;
            }
        }

        return sum;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[701525690,453694317],[954853451,571451509],[691549168,895570156],[765408118,904408040],[230743058,788990029],[817142128,623576430],[312349756,258258330],[998390174,339475009],[700184025,431308850],[558751425,702072019],[190818738,418700527],[112109100,645793905]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,4],[1,2],[7,8],[2,3]]\n
// @lcpr case=end

 */

