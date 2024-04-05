/*
 * @lc app=leetcode.cn id=622 lang=cpp
 * @lcpr version=30121
 *
 * [622] 设计循环队列
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
class MyCircularQueue {
public:
    vector<int> q;
    int front,rear;
    MyCircularQueue(int k) {
        cout<<"MyCircularQueue"<<endl;
        q.resize(k+1);
        front=0; // 出栈元素的下一个 如果有元素，则指向第一个元素
        rear=0; // 最后一个元素的下一个
    }
    
    bool enQueue(int value) {
        cout<<"enQueue"<<endl;
        if(this->isFull())return false;
        q[rear]=value;
        rear=(rear+1)%q.size(); //不能++，需要取模
        return true;
    }
    
    bool deQueue() {
        cout<<"deQueue"<<endl;
        if(this->isEmpty())return false;
        front=(front+1)%q.size();
        return true;
    }
    
    int Front() {
        cout<<"Front"<<endl;
        if(this->isEmpty()) return -1;
        return q[front];
    }
    
    int Rear() {
        cout<<"Rear"<<endl;
        if(this->isEmpty()) return -1;
        return q[(rear-1+q.size())%q.size()];
    }
    
    bool isEmpty() {
        cout<<"isEmpty"<<endl;
        return front==rear;
    }
    
    bool isFull() {
        cout<<"isFull"<<endl;
        return (rear+1)%q.size()==front;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end

// @lcpr case=start
// ["MyCircularQueue","enQueue","enQueue","deQueue","enQueue","deQueue","enQueue","deQueue","enQueue","deQueue", "Front"]\n
// @lcpr case=end


