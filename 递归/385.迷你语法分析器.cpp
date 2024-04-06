/*
 * @lc app=leetcode.cn id=385 lang=cpp
 * @lcpr version=30121
 *
 * [385] 迷你语法分析器
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
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

// class NestedInteger {
//     public:
//         // Constructor initializes an empty nested list.
//         NestedInteger();
//         // Constructor initializes a single integer.
//         NestedInteger(int value);
//         // Return true if this NestedInteger holds a single integer, rather than a nested list.
//         bool isInteger() const;
//         // Return the single integer that this NestedInteger holds, if it holds a single integer
//         // The result is undefined if this NestedInteger holds a nested list
//         int getInteger() const;
//         // Set this NestedInteger to hold a single integer.
//         void setInteger(int value);
//         // Set this NestedInteger to hold a nested list and adds a nested integer to it.
//         void add(const NestedInteger &ni);
//         // Return the nested list that this NestedInteger holds, if it holds a nested list
//         // The result is undefined if this NestedInteger holds a single integer
//         const vector<NestedInteger> &getList() const;
// };

class Solution {
public:
    int convert(string s){
        if(s[0]=='-'){
            return -convert(s.substr(1,s.size()-1));
        }
        int ans=0, i=0;
        while(i<s.size()){
            ans*=10;
            ans+=s[i]-'0';
            i++;
        }
        return ans;
    }

    NestedInteger deserialize(string s) {
        int i=0,j, n=s.size();

        j=i; // 如果外面没有列表，从0开始遍历
        if(s[i]>='0' && s[i]<='9' || s[i]=='-'){ // 这里需要遍历到最后一个
            while(j<n && (s[j]>='0' && s[j]<='9' || s[j]=='-')){ // python字符计算
                j++;
            }j--;
            int tmp= convert(s.substr(i, j-i+1));
            return (NestedInteger(tmp));

            i=j;
        }


        i=1;
        NestedInteger ans;


        while(i<n-1){   //1 到n-2，舍去头尾的元素
            j=i;
            if(s[i]>='0' && s[i]<='9' || s[i]=='-'){
                while(j<n-1 && (s[j]>='0' && s[j]<='9' || s[j]=='-')){ // python字符计算
                    j++;
                }j--;
                int tmp= convert(s.substr(i, j-i+1));
                ans.add(NestedInteger(tmp));

                i=j;
            }else if(s[i]=='['){
                int commaNum=0;
                while(j<n-1){ 
                    if( s[j]=='['){
                        commaNum++;
                    }else if(s[j]==']'){
                        commaNum--;
                        if(commaNum==0){
                            break;
                        }
                    }
                    j++;
                }
                ans.add(deserialize(s.substr(i,j-i+1)));

                i=j;
            }
            i++;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "324"\n
// @lcpr case=end

// @lcpr case=start
// "[123,[456,[789]]]"\n
// @lcpr case=end

 */

