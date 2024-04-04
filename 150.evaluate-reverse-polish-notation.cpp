/*
 * @lc app=leetcode.cn id=150 lang=cpp
 * @lcpr version=30121
 *
 * [150] 逆波兰表达式求值
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
// 波兰表达式时后缀表达式，去掉括号没有歧义
// 需要一个栈：遇到数字则入栈；遇到运算符则取出栈顶两个数字进行计算，并将结果压入栈
    int convert(string str){
        if(str[0]=='-'){ //呃呃
            return -convert(str.substr(1)); //默认最后
        }
        int ans=0;
        for(int i=0;i<str.size();i++){
            ans*=10;
            ans+=str[i]-'0'; // python 怎么处理
        }
        return ans;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        auto getTwoNum = [&]() -> std::tuple<int, int> { // 访问房前作用域中的所有变量
            int y = s.top(); s.pop();
            int x = s.top(); s.pop();
            return {x, y}; // 返回一个包含两个整数的tuple
        };
        
        for(auto & str:tokens){
            if(str=="+"){
                auto[x,y]=getTwoNum(); //更简洁
                s.push(x+y);
            }else if (str=="-"){
                auto[x,y]=getTwoNum();
                s.push(x-y);
            }else if (str=="*"){
                auto[x,y]=getTwoNum();
                s.push(x*y);
            }else if (str=="/"){
                auto[x,y]=getTwoNum();
                s.push(x/y);
            }else{
                s.push(convert(str));
            }   
        }
        return s.top();
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["2","1","+","3","*"]\n
// @lcpr case=end

// @lcpr case=start
// ["4","13","5","/","+"]\n
// @lcpr case=end

// @lcpr case=start
// ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]\n
// @lcpr case=end

// @lcpr case=start
// ["3","-4","+"]\n
// @lcpr case=end
 */

