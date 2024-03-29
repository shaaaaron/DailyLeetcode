/*
 * @lc app=leetcode.cn id=678 lang=cpp
 * @lcpr version=30121
 *
 * [678] 有效的括号字符串
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
    bool checkValidString(string s) {
        int left=0,star=0,right=0;
        int n =s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='(')left++;
            else if(s[i]=='*')star++;
            else right++;

            if(right>left){
                if(star>=right-left){
                    star-=(right-left);
                    left+=(right-left);
                }else{
                    return false;
                }
            }
        }
        cout<<left<<" "<<star<<" "<<right<<endl;
        if(star>=left-right)return true;
        return false;
    }
};

// "(((((*(((((*((**(((*)*((((**))*)*)))))))))((*(((((**(**)"

/*

// @lcpr case=start
// "(((((*(*********((*(((((****"\n
// @lcpr case=end

// @lcpr case=start
// "())*"\n
// @lcpr case=end

// @lcpr case=start
// "(*)"\n
// @lcpr case=end

// @lcpr case=start
// "(*))"\n
// @lcpr case=end

 */

