/*
 * @lc app=leetcode.cn id=37 lang=cpp
 * @lcpr version=30122
 *
 * [37] 解数独
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
    bool check(int i,int j, vector<vector<char>>& board){ // ij是刚填充的数字，检查是不是合法
        for(int k=0;k<9;k++){
            if(k==j)continue;
            if(board[i][k]==board[i][j]) return false;
        }
        for(int k=0;k<9;k++){
            if(k==i)continue;
            if(board[k][j]==board[i][j]) return false;
        }

        int box_i=i/3, box_j=j/3;
        for(int ii=3*box_i;ii<3*box_i+3;ii++){
            for(int jj=3*box_j;jj<3*box_j+3;jj++){
                if(i==ii && j==jj) continue;
                if(board[i][j]==board[ii][jj])
                    return false;
            }
        }
        return true;
    }

    bool bt(vector<vector<char>>& board){ // 有两种方案，将可行结果添加到ans或者return bool。由于保证恰好一个结果，所以bool
    // 方便起见，直接从头开始找
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.')continue;

                for(int val=1;val<=9;val++){
                    board[i][j]=val+'0';
                    if(check(i,j, board)){
                        bool flag = bt(board);
                        if(flag) return true; // 找到了立刻终止
                    }
                    board[i][j]='.';
                }
                return false;
            }
        }
        return true; //必须有且为true，说明满了
    }

    void solveSudoku(vector<vector<char>>& board) {
        bt(board);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]\n
// @lcpr case=end

 */

