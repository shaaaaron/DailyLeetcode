/*
 * @lc app=leetcode.cn id=232 lang=cpp
 * @lcpr version=30121
 *
 * [232] 用栈实现队列
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
class MyQueue {
public:
// 两个栈进行腾挪
    stack<int> s1,s2;
    MyQueue() {

    }
    
    void push(int x) {
        s2.push(x);
    }
    
    int pop() {
        if(!s1.empty()){
            int ans=s1.top();
            s1.pop();
            return ans;
        }else{
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
            int ans=s1.top();
            s1.pop();
            return ans;
        }
    }
    
    int peek() {    // 考虑代码复用问题
        if(!s1.empty()){
            return s1.top();
        }else{
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
            return s1.top();
        }
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end



/*
// @lcpr case=start
// ["MyQueue", "push", "push", "peek", "pop", "empty"][[], [1], [2], [], [], []]\n
// @lcpr case=end

 */

