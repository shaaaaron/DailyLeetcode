/*
 * @lc app=leetcode.cn id=1284 lang=cpp
 * @lcpr version=30122
 *
 * [1284] 转化为全零矩阵的最少反转次数
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
// 注意到3*3，所以想到回溯
// 关键点在于，操作两次相当于不操作
    void flip(int x,int y, vector<vector<int>>& mat){
        int m=mat.size(),n=mat[0].size();
        vector<pair<int,int>> dirs={{-1,0},{1,0},{0,-1},{0,1}};
        mat[x][y]=1-mat[x][y];// 自己也要操作
        for(auto pr : dirs){
            int dx=pr.first, dy=pr.second;
            if(x+dx<0 || x+dx>=m || y+dy<0 || y+dy>=n) continue;
            mat[x+dx][y+dy]=1-mat[x+dx][y+dy];
        }
    }

    bool check(vector<vector<int>>& mat){
        int m=mat.size(),n=mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]!=0) return false;
            }
        }
        return true;
    }

    int minFlips(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        int ans=INT_MAX;
        vector<vector<int>> mat_record=mat;
        for(int state=0; state<=(1<<m*n)-1; state++){
            int i=0,j=0;
            int state_record=state; // mat和state都需要保存
                                    // 最好是复制一个新的来操作
            mat=mat_record;
            while(state){
                if(state&1){
                    flip(i,j,mat);
                }
                state>>=1;
                j++; // 每次只更新j
                if(j==n){
                    i++;
                    j=0;
                }
            }

            // cout<<state_record<<endl;
            // for(int i=0;i<m;i++){
            //     for(int j=0;j<n;j++){
            //         cout<<mat[i][j];
            //     }cout<<endl;
            // }
            if(check(mat)){
                ans=min(ans, __builtin_popcount(state_record));
            }

            state=state_record; // 记录或者干脆别用
        }
        return ans==INT_MAX?-1:ans;// 判断是不是可行的
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,0],[0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,0],[1,0,0]]\n
// @lcpr case=end

 */

