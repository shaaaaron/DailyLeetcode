/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValid(string s){
        if(s.size()==1){
            if(s[0]>='1' && s[0]<='9'){
                return true;
            }else{
                return false;
            }
        }else if(s.size()==2){
            if(s[0]=='1'&&s[1]>='0'&&s[1]<='9')return true;
            if(s[0]=='2'&&s[1]>='0'&&s[1]<='6')return true;
            return false;
        }
        return false;
    }

    int numDecodings(string s) {
        if(s.size()==1){
            if(isValid(s)) return 1;
            else return 0;
        }
        if(s.size()==2){
            int ans=0;
            if(isValid(s)) ans+=1;
            if(isValid(string(1,s[0])) && isValid(string(1,s[1]))) ans+=1;
            return ans;
        }

        int num1,num2=0;
        if(isValid(s.substr(0,1))) num1=1;
        else num1=0;
        if(isValid(s.substr(0,2))) num2+=1;
        if(isValid(string(1,s[0])) && isValid(string(1,s[1]))) num2+=1;

            cout<<num1<<" "<<num2<<endl;
        for(int i=2;i<s.size();i++){
            int num3 =0;
            if(isValid(s.substr(i-1,2))) num3+=num1;
            if(isValid(s.substr(i,1))) num3+=num2;
            num1=num2;
            num2=num3;
            cout<<num1<<" "<<num2<<endl;
        }
        return num2;

    }
};
// @lc code=end

// int main(){
//     Solution test;
//     string a;
//     cin>>a;
//     cout<<test.numDecodings(a);
//     return 0;
// }

