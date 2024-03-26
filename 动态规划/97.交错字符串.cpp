/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */

// @lc code=start
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // 边界：空字符串

        if(s1.size()+s2.size() != s3.size()) return false;

        int m=s1.size(), n= s2.size();
        vector<int> a(n+1,0);

        for(int i=0;i<= n;i++){
            if(i==0){
                a[0] = 1;
            }else{
                if(a[i-1]==0){
                    a[i]=0;
                }else{
                    a[i] = s2[i-1]==s3[i-1]? 1:0;
                }
            }
        }

        for(int i=1;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(j==0){
                    a[j]=s1.substr(0,i) == s3.substr(0,i)?1:0;
                }else{
                    a[j]=a[j]&&s1[i-1]==s3[i+j-1] || a[j-1] && s2[j-1]==s3[i+j-1]?1:0;
                }
            }
        }
        return a[n]==1;
    }
};
// @lc code=end


int main() {
    string s1="", s2= "aabcc", s3="aabcc";
    cout<<(Solution().isInterleave(s1,s2,s3));
    return 0;
}
