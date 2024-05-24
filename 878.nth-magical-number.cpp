/*
 * @lc app=leetcode.cn id=878 lang=cpp
 * @lcpr version=30202
 *
 * [878] 第 N 个神奇数字
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
    int ldm(long long x, long long y){
        long long tx=x, ty=y;
        if(tx>ty) swap(tx,ty);
        while(tx>0){
            long long tmp=ty%tx;
            ty=tx;
            tx=tmp;
        }
        // ty是最大公因数
        return x/ty*y; // 最小公倍数
    }
    // 另外一个简单的，但是无法通过本题的做法是二路归并

    int nthMagicalNumber(int n, int a, int b) {
        long long lt=1, rt=LONG_LONG_MAX; // 也可以将rt设置为当前满足的最大值，这里是max(a,b)*n
        const long long LDM_ab=ldm(a, b);
        while(lt<=rt){
            long long md=lt+(rt-lt)/2; // 防止越界
            long long tmp=md/a+md/b-md/LDM_ab;
            if(tmp>=n){ // 注意二段性，写起来就很简单
                rt=md-1;
            }else{
                lt=md+1;
            }
        }

        const int PRIME=1000*1000*1000+7; // 注意这里是int，所以下面会把longlong降为int
        // 如果longlong直接转int并且越界可能导致负数的问题
        return lt%PRIME;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n2\n3\n
// @lcpr case=end

// @lcpr case=start
// 4\n2\n3\n
// @lcpr case=end

 */

