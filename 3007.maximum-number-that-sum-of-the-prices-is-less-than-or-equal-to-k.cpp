/*
 * @lc app=leetcode.cn id=3007 lang=cpp
 * @lcpr version=30122
 *
 * [3007] 价值和小于等于 K 的最大数字
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
// 用试填法的思路，很容易想到二分
    long long findMaximumNumber(long long k, int x) {
        long long lt=1, rt=((long long)1<<x)*k;// 不能max，可能越界
        while(lt<=rt){
            long long md=lt+(rt-lt)/2;

            long long ans=0;
            for(int bit=x-1;bit<62;bit+=x){
                long long loop=(long long)1<<(bit+1);//不能满到63，否则会越界
                ans+=md/loop*loop/2;
                if(md%loop<=loop/2-1){// 构造bit
                    ans+=0;
                }else if(md%loop>loop/2-1 && md%loop<=loop-1){
                    ans+=md%loop-loop/2+1;
                }else{
                    ans+=loop/2;
                }
            }
            if(ans<=k){
                lt=md+1;
            }else{
                rt=md-1;
            }
        }
        return lt-1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 9\n1\n
// @lcpr case=end

// @lcpr case=start
// 7\n2\n
// @lcpr case=end
// @lcpr case=start
// 1000000000000000\n8\n
// @lcpr case=end
// @lcpr case=start
// 1000000000000\n7\n
// @lcpr case=end
// @lcpr case=start
// 100000000\n3\n
// @lcpr case=end
// @lcpr case=start
// 12324124124\n6\n
// @lcpr case=end
// @lcpr case=start
// 123\n2\n
// @lcpr case=end
// @lcpr case=start
// 4124\n1\n
// @lcpr case=end
// @lcpr case=start
// 111\n7\n
// @lcpr case=end
// @lcpr case=start
// 1000\n1\n
// @lcpr case=end
// @lcpr case=start
// 9345345\n2\n
// @lcpr case=end
// @lcpr case=start
// 123124\n2\n
// @lcpr case=end

 */

