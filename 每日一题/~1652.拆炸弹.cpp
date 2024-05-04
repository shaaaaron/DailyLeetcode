/*
 * @lc app=leetcode.cn id=1652 lang=cpp
 * @lcpr version=30122
 *
 * [1652] 拆炸弹
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
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        if(k==0){ // 最好不同情况都写ans，但是不return 
            return vector<int>(n, 0);
        }else if(k>0){
            vector<int> ans(n, 0);

            int sum=0;
            int idx=1;
            for(int i=1;i<=k;i++){ // for循环计算次数，具体位置由另一个决定
                                    // 一个个向后遍历保证不出错
                sum+=code[idx];
                idx=(idx+1)%n;  // 所有指针的移动都需要模运算
            }
            int lt=1, rt=k%n;
            for(int i=0;i<n;i++){
                ans[i]=sum;
                rt=(rt+1)%n; // 注意闭区间的更新方法
                sum+=code[rt];
                sum-=code[lt];
                lt=(lt+1)%n;
            }
            return ans;
        }else{
            vector<int> ans(n, 0);
            k=-k; // 校正为正数，不能当作负数处理

            int sum=0;
            int idx=(n-k+n)%n;
            for(int i=1;i<=k;i++){ // 应该一个个向前遍历，这样的化如果k超过size可能出错
                sum+=code[idx];
                idx=(idx+1)%n;
            }
            int lt=(n-k+n)%n, rt=(n-1+n)%n;
            for(int i=0;i<n;i++){
                ans[i]=sum;
                rt=(rt+1)%n;
                sum+=code[rt];
                sum-=code[lt];
                lt=(lt+1)%n;
            }
            return ans;
        }

        return {-1}; // {}可以，但是()不可以
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,7,1,4]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n0\n
// @lcpr case=end

// @lcpr case=start
// [2,4,9,3]\n-2\n
// @lcpr case=end

 */

