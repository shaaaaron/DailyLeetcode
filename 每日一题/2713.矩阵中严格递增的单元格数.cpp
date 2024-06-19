/*
 * @lc app=leetcode.cn id=2713 lang=cpp
 * @lcpr version=30203
 *
 * [2713] 矩阵中严格递增的单元格数
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
    typedef pair<int,int> PII;
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        vector<int> row_max(m), col_max(n);
        vector<PII> idx(m*n);
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                idx[i*n+j]={i,j};
            }
        }
        sort(idx.begin(), idx.end(), [&](PII&x, PII&y){
            return mat[x.first][x.second]<mat[y.first][y.second];
        });
        int i=0,j;
        while(i<m*n){
            j=i;
            while(j<m*n && mat[idx[j].first][idx[j].second]==mat[idx[i].first][idx[i].second]){
                ++j;
            }// [i, j)为相同元素
            vector<int> tmp;    // 对于相同数值的元素需要统一处理完，才能更新，临时结果存放在tmp中
            for(int k=i;k<j;k++){
                int x=idx[k].first, y=idx[k].second;
                tmp.push_back(max(row_max[x], col_max[y])+1);
            }
            for(int k=i;k<j;k++){
                int x=idx[k].first, y=idx[k].second;
                row_max[x]=max(row_max[x], tmp[k-i]);
                col_max[y]=max(col_max[y], tmp[k-i]);
            }
            i=j;    // 双指针i更新
        }

        return *max_element(row_max.begin(), row_max.end());// 由于行列的最大值是相等的，所以只需要返回一个
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[3,1],[3,4]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,1,6],[-9,5,7]]\n
// @lcpr case=end

 */

