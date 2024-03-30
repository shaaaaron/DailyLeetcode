/*
 * @lc app=leetcode.cn id=688 lang=cpp
 * @lcpr version=30121
 *
 * [688] 骑士在棋盘上的概率
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
    // 直接进行概率的计算。而不是先算方法再算概率
    // 否则会溢出
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> a(n, vector<double>(n,0));
        a[row][column]=1;

        // tuple的初始化和使用方法
        vector<pair<int, int>> dxy{{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,-2},{-1,2}};
        double outPro=0;

        for(int step=1; step<=k; step++){
            vector<vector<double>> a_new(n, vector<double>(n,0));
            // int outNum =0, inNum=0;


            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    for(auto &dx_dy: dxy){
                        if(i+dx_dy.first>=0 && i+dx_dy.first<n && j+dx_dy.second>=0 && j+dx_dy.second<n){
                            a_new[i+dx_dy.first][j+dx_dy.second]+=1.0/8*a[i][j];
                        }else{
                            outPro+=1.0/8*a[i][j];
                        }
                    }
                }
            }
            a=a_new;
        }
        return 1-outPro;
    }
};
// @lc code=end



/*

// @lcpr case=start
// 8\n30\n6\n4\n
// @lcpr case=end

// @lcpr case=start
// 3\n2\n1\n1\n
// @lcpr case=end

// @lcpr case=start
// 1\n0\n0\n0\n
// @lcpr case=end

 */

