/*
 * @lc app=leetcode.cn id=1106 lang=cpp
 * @lcpr version=30121
 *
 * [1106] 解析布尔表达式
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
    bool parseBoolExpr(string expression) {
        stack<char> st; // 用st不会和字符串混淆
        int i=0, n=expression.size();
        for(i=0;i<n;i++){
            if(expression[i]==')'){
                bool and_ans=true, or_ans=false;//不同的初始化
                bool tmp;
                while(st.top()!='('){
                    tmp=st.top()=='t'?true:false;
                    and_ans=and_ans&&tmp;
                    or_ans=or_ans||tmp;
                    st.pop();
                }
                st.pop();
                if(st.top()=='!'){
                    tmp=!tmp;
                }else if(st.top()=='&'){
                    tmp=and_ans;
                }else if(st.top()=='|'){
                    tmp=or_ans;
                }
                st.pop();
                st.push(tmp?'t':'f');   // 中间过程是字符，不是bool
                // std::stack的top()函数返回的是栈顶元素的引用，但是并不允许直接修改该引用。如果要修改栈顶元素，需要先将栈顶元素弹出，然后再将修改后的元素推入栈顶
            }else if(expression[i]!=','){ // 逗号全部省略
                st.push(expression[i]);
            }
        }
        return st.top()=='t';// 最后一定只有一个元素
                            // 结尾是bool不是字符
    }
};
// @lc code=end



/*
// @lcpr case=start
// "|(f,&(t,t))"\n
// @lcpr case=end
// @lcpr case=start
// "&(|(f))"\n
// @lcpr case=end

// @lcpr case=start
// "|(f,f,f,t)"\n
// @lcpr case=end

// @lcpr case=start
// "!(&(f,t))"\n
// @lcpr case=end

 */

