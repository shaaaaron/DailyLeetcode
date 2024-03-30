/*
 * @lc app=leetcode.cn id=799 lang=cpp
 * @lcpr version=30121
 *
 * [799] 香槟塔
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
    double champagneTower(int poured, int query_row, int query_glass) {

        vector<double> a{double(250.0*poured)},b;// 当前的杯子

        for(int i=0;i<=query_row;i++){
            b.resize(a.size()+1, 0);//流出去的,resieze进行初始化
                                    // resize只会对resize新弄出来的元素初始化！
            for(int j=0;j<b.size();j++) b[j]=0;

            for(int j=0;j<a.size();j++){
                if(a[j]>250){
                    b[j]+=(a[j]-250)/2;  // 累加不是赋值
                    b[j+1]+=(a[j]-250)/2;
                    a[j]=250;
                }
            }

            // 如果现在是最后一行
            if(i==query_row) return a[query_glass]/250;
            a=b;// 更新, 无论ab的大小，都会把a变成b，没有问题
                // 但是留个心眼小心编译器实现，可以assert
                // 确定了，leetcode也没问题，放心用
        }
        return 0; // leetcode因为版本原因，最后都是要有返回
    }
};
// @lc code=end



/*
// @lcpr case=start
// 25\n6\n1\n
// @lcpr case=end

// @lcpr case=start
// 2\n1\n1\n
// @lcpr case=end

// @lcpr case=start
// 100000009\n33\n17\n
// @lcpr case=end

 */

