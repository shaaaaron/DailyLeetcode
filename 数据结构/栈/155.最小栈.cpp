/*
 * @lc app=leetcode.cn id=155 lang=cpp
 * @lcpr version=30121
 *
 * [155] 最小栈
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
class MinStack {
public:
// 小顶堆是删除最小元素，本题则是按顺序出栈
// 原理是从左到右，min会越来越小
    stack<int> s_min,s;
    MinStack() {

    }
    
    void push(int val) {
        if(s_min.empty()){
            s_min.push(val);
        }else{
            s_min.push(min(s_min.top(), val));
        }

        s.push(val);
    }
    
    void pop() {
        s_min.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return s_min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end



/*
// @lcpr case=start
// ["MinStack","push","push","push","getMin","pop","top","getMin"][[],[-2],[0],[-3],[],[],[],[]]\n
// @lcpr case=end

 */

