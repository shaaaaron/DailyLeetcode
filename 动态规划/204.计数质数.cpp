/*
 * @lc app=leetcode.cn id=204 lang=cpp
 * @lcpr version=30121
 *
 * [204] 计数质数
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
#include <cmath>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        if(n==0 || n==1 ||n==2) return 0; // 小的实在太奇怪了
        vector<int> a(n, 1);
        a[1]=0;
        int i;
        int ans=0;
        for(i=2;i<=int(sqrt(n)+1) && i<n;i++){ // python中如何开方 // 通过两个判断防止越界
                                                // 除去1
            if(a[i]==0) continue;

            for(int j=2*i;j<n;j+=i){    // 循环条件
                a[j]=0;
            }
        }

        for(int i=1;i<n;i++){
            if(a[i]==1) ans++;
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 10\n
// @lcpr case=end

// @lcpr case=start
// 0\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 4\n
// @lcpr case=end
 */

