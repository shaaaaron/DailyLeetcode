/*
 * @lc app=leetcode.cn id=203 lang=cpp
 * @lcpr version=30121
 *
 * [203] 移除链表元素
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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* fake_head=new ListNode(0,head);

        ListNode* before=fake_head, *curr;
        while(before->next !=nullptr){
            curr=before->next;
            // 实际上是curr移动
            // 如果删除了元素，则before不移动！
            // 如果没有删除元素，则before移动
            if(curr->val == val){
                before->next=curr->next;
                delete curr;
            }else{
                before=before->next;
            }
        }

        before=fake_head->next;
        delete fake_head;
        return before;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,6,3,4,5,6]\n6\n
// @lcpr case=end

// @lcpr case=start
// []\n1\n
// @lcpr case=end

// @lcpr case=start
// [7,7,7,7]\n7\n
// @lcpr case=end

 */

