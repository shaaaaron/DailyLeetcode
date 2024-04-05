/*
 * @lc app=leetcode.cn id=1670 lang=cpp
 * @lcpr version=30121
 *
 * [1670] 设计前中后队列
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
class FrontMiddleBackQueue {
public:
// 如果没有明说使用队列能不能想到
// 实现O1的查询mid功能
    deque<int> q1,q2; // 如果占总数为奇数，q1更小
    FrontMiddleBackQueue() {

    }
    
    void pushFront(int val) {
        q1.push_front(val);
        if(q1.size() == q2.size()+1){
            int tmp=q1.back();
            q1.pop_back();
            q2.push_front(tmp);
        }
    }
    
    void pushMiddle(int val) {
        if(q1.size()==q2.size()){
            q2.push_front(val);
        }else{
            q1.push_back(val);
        }
    }
    
    void pushBack(int val) {
        q2.push_back(val);
        if(q1.size()+2==q2.size()){
            int tmp=q2.front();
            q2.pop_front();
            q1.push_back(tmp);
        }
    }
    
    // int popFront() {
    //     int x=q1.front();
    //     if(q1.size()!=q2.size()){ // q1中可能没有元素导致出界
    //         int tmp=q2.front();
    //         q2.pop_front();
    //         q1.push_back(tmp);
    //     }
    //     q1.pop_front();
    //     return x;
    // }

    int popFront() {
        if(q1.size()+q2.size()==0)return -1; // 特殊处理
        if(q1.size()+1==q2.size()){ //处理的时候防止越界，例如处理01的情况
            int tmp=q2.front();     //应该先移动元素然后q1pop front。先q1 pop在01的情况下就会出错
            q2.pop_front();
            q1.push_back(tmp);
        }
        int x=q1.front();
        q1.pop_front();
        return x;
    }
    
    int popMiddle() {    
        if(q1.size()+q2.size()==0)return -1;    
        if(q1.size()+1==q2.size()){
            int tmp=q2.front();
            q2.pop_front();
            q1.push_back(tmp);
        }
        int x=q1.back();
        q1.pop_back();

        return x;
    }
    
    int popBack() {
        if(q1.size()+q2.size()==0)return -1;
        int x=q2.back();
        q2.pop_back();
        if(q1.size()==q2.size()+1){
            int tmp=q1.back();
            q1.pop_back();
            q2.push_front(tmp);
        }
        return x;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
// @lc code=end



/*
// @lcpr case=start
// ["FrontMiddleBackQueue", "pushFront", "pushBack", "pushMiddle", "pushMiddle", "popFront", "popMiddle", "popMiddle","popBack", "popFront"][[], [1], [2], [3], [4], [], [], [], [], []]\n
// @lcpr case=end

 */

