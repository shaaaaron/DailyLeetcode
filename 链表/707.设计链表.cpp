/*
 * @lc app=leetcode.cn id=707 lang=cpp
 * @lcpr version=30121
 *
 * [707] 设计链表
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

struct Node{ // class似乎有问题，需要struct
    Node * next;
    int val;
    Node():val(0),next(nullptr){}
    Node(int val):val(val),next(nullptr){}
    Node(int val, Node* next):val(val),next(next){}
};

class MyLinkedList {
public:
    Node*head;
    MyLinkedList() {
        head=new Node();
    }
    
    int get(int index) {
        Node *before=head, *curr=head->next;
        int curr_index=0;
        while(curr_index<=index){
            if(curr==nullptr) return -1;

            if(curr_index==index){
                return curr->val;
            }

            before=curr;
            curr=curr->next;
            curr_index++;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        Node * tmp=new Node(val,head->next);
        head->next=tmp;
        return;
    }
    
    void addAtTail(int val) {
        Node* before=this->head, *curr=head->next;
        while(curr!=nullptr){
            before=curr;
            curr=curr->next;
        }  
        before->next=new Node(val, nullptr);
        return;
    }
    
    void addAtIndex(int index, int val) {
        Node* before=this->head, *curr=head->next;
        int curr_index=0;
        while(curr_index<=index){

            if(curr_index==index){
                Node* tmp=new Node(val);
                tmp->next=curr;
                before->next=tmp;
                return;
            }

            if(curr==nullptr)return;//顺序

            before=curr;
            curr=before->next;
            curr_index++;
        }
        return;
    }
    
    void deleteAtIndex(int index) {
        Node* before=this->head, *curr=head->next;
        int curr_index=0;
        while(curr_index<=index){
            if(curr==nullptr)break;

            if(curr_index==index){
                before->next=curr->next;
                delete curr;
                break;
            }

            before=curr;
            curr=before->next;
            curr_index++;
        }
        return;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end



