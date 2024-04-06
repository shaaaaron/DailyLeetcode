/*
 * @lc app=leetcode.cn id=225 lang=cpp
 * @lcpr version=30121
 *
 * [225] 用队列实现栈
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
class MyStack {
public:
// 本质上只需要一个元素，两个是题目的要求
    queue<int> q1,q2;
    MyStack() {

    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size()>=2){ //是2不是1
            q2.push(q1.front());
            q1.pop();   // 更新
        }

        int ans=q1.front();
        q1.pop();
        while(q2.size()>=1){// 是1不是0
            q1.push(q2.front());
            q2.pop();
        }
        return ans;
    }
    
    int top() {
        int ans=this->pop();
        this->push(ans);
        return ans;
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end



/*
// @lcpr case=start
// ["MyStack", "push", "push", "top", "pop", "empty"][[], [1], [2], [], [], []]\n
// @lcpr case=end

 */

