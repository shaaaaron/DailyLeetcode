/*
 * @lc app=leetcode.cn id=1738 lang=cpp
 * @lcpr version=30202
 *
 * [1738] 找出第 K 大的异或坐标值
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
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m=matrix.size(), n=matrix[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dp[i+1][j+1]=dp[i+1][j]^dp[i][j+1]^dp[i][j]^matrix[i][j];
            }
        }

        vector<int> res;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                res.push_back(dp[i][j]);
            }
        }
        
        // 注释输出代码，否则超时
        // for(int i=0;i<res.size();i++){
        //     cout<<res[i]<<" ";
        // }cout<<endl;

        // 使用迭代器作为函数参数比较复杂，建议使用下标
        function<int(int,int,int)> qselect=[&](int k, int lt, int rt){
            if(lt == rt-1) return res[lt];
            int i=lt, j=lt;
            int pivot=res[rt-1];
            for(int i=lt;i<=rt-1-1;i++){
                if(res[i]<pivot){
                    swap(res[i], res[j]);
                    j++;
                }
            }
            swap(res[j], res[rt-1]); 
            if(j==lt+k) return pivot;
            if(j< lt+k) return qselect(k-(j-lt+1), j+1, rt);  
            return qselect(k, lt, j);
        };

        // return qselect(res.size()-k, 0, res.size());
        
        // 提供的是迭代器位置，在对应位置防止元素，其他位置不保证有序
        // 速度远快于自己实现
        nth_element(res.begin(), res.begin() + k - 1, res.end(), greater<int>());
        return res[k - 1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[5,2],[1,6]]\n1\n
// @lcpr case=end

// @lcpr case=start
// [[5,2],[1,6]]\n2\n
// @lcpr case=end

// @lcpr case=start
// [[5,2],[1,6]]\n3\n
// @lcpr case=end

// @lcpr case=start
// [[5,2],[1,6]]\n4\n
// @lcpr case=end

 */

