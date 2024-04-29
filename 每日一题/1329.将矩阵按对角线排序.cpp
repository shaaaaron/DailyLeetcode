/*
 * @lc app=leetcode.cn id=1329 lang=cpp
 * @lcpr version=30122
 *
 * [1329] 将矩阵按对角线排序
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
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();

        for(int i=0;i<m;i++){
            vector<int> tmp;
            for(int x=i, y=0; x<m && y<n; x++, y++){
                tmp.push_back(mat[x][y]);
            }
            sort(tmp.begin(), tmp.end());
            for(int x=i, y=0; x<m && y<n; x++, y++){
                mat[x][y]=tmp[y];
            }
        }

        for(int j=1;j<n;j++){
            vector<int> tmp;
            for(int x=0, y=j; x<m && y<n; x++, y++){
                tmp.push_back(mat[x][y]);
            }
            sort(tmp.begin(), tmp.end());
            for(int x=0, y=j; x<m && y<n; x++, y++){
                mat[x][y]=tmp[x];
            }
        }

        return mat;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[3,3,1,1],[2,2,1,2],[1,1,1,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[11,25,66,1,69,7],[23,55,17,45,15,52],[75,31,36,44,58,8],[22,27,33,25,68,4],[84,28,14,11,5,50]]\n
// @lcpr case=end

 */

