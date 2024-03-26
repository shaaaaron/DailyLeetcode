/*
 * @lc app=leetcode.cn id=464 lang=cpp
 *
 * [464] 我能赢吗
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // 完全写错，你写成了先手能获得的最大整数值，但这是显然的
    // int dp_order(int i, int j, vector<vector<int>> a, bool first){
    //     //当次是否先手，上一次是否为偶数（mod2整除）
    //     if(first){
    //         return a[i][j];
    //     }else{
    //         return (i+j)*(j-i+1)/2-a[i][j];
    //     }
    // }

    // bool canIWin(int maxChoosableInteger, int desiredTotal) {
    //     int n=maxChoosableInteger;
    //     // int a[n+1][n+1]={};
    //     vector<vector<int>> dp (n+1,vector<int>(n+1,0)); // 初始化为0，大小是否合适
    //     for(int i=1;i<=n;i++)   dp[i][i]  =i;
    //     for(int i=1;i<n;i++)    dp[i][i+1]=i+1;

    //     for(int interval_len=1;interval_len<=n;interval_len++){ // [1,1]的长度为1
    //         for(int i=1;i<=n-interval_len+1;i++){ // 当前区间是[i, i+len-1]
    //             int j=i+interval_len-1;
    //             if(i==j||i+1==j) continue;
    //             int tmp_score = -1;
    //             for(int mid=i+1;mid<=j-1;mid++){
    //                 // if(mid==i||mid==j){}else{ 不需要处理这种情况。什么时候需要处理
    //                     int a1=dp[i][mid-1]+dp_order(mid,j,dp,(mid-i)%2==0);
    //                     int a2=dp[mid+1][j]+dp_order(i,mid,dp,(j-mid)%2==0);
    //                     int a3=mid;
    //                     a3+=min(dp_order(i,mid-1,dp,(1)%2==0) + dp_order(mid+1,j,dp,(mid-i+1)%2==0),
    //                             dp_order(mid+1,j,dp,(1)%2==0) + dp_order(i,mid-1,dp,(j-mid+1)%2==0));
    //                     int score = max(a1,max(a2,a3)); // 
    //                     if(score>tmp_score){
    //                         tmp_score = score;
    //                     }
    //                 // }
    //             }
    //             dp[i][j]=tmp_score;
    //             // cout<<"["<<i<<", "<<j<<"]: "<<dp[i][j]<<", ";
    //         }
    //     }
    //     for(int i=1;i<=n;i++){
    //         for(int j=i;j<=n;j++){
    //             cout<<"["<<i<<", "<<j<<"]: "<<dp[i][j]<<", ";
    //         }
    //         cout<<endl;
    //     }
    //     return dp[1][n]>=desiredTotal;
    // }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        
    }

};
// @lc code=end
// 累计整数和

int main() {
    // TODO: Write your C++ code here
    cout<<Solution().canIWin(5,9);
    return 0;
}
