/*
 * @lc app=leetcode.cn id=109 lang=cpp
 * @lcpr version=30121
 *
 * [109] 有序链表转换二叉搜索树
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* maketree(ListNode* head, ListNode* end){ // 最后一个可能为空，不要实际修改链表
        if(head==nullptr) return nullptr;   // 递归中处理null
        if(head==end) return nullptr;
        if(head->next==end) return new TreeNode(head->val); // 由于递归中是将中间元素拿出来，分别处理前后的子链表。可以注意到长度为head==end和长度为1的链表都会出错，所以需要特殊处理

        int n=0;
        ListNode* iter=head;
        while(iter!=end){
            n++;
            iter=iter->next;
        }

        // int mid=n/2;  这是错误的，应该使用下面一行
        int mid=(n+1)/2; // 第n/2个节点
        iter=head;
        for(int i=0;i<mid -1;i++){ // 向后移动mid-1个节点
            iter=iter->next;
        }

        TreeNode *root=new TreeNode(iter->val);
        root->left=maketree(head, iter);
        root->right=maketree(iter->next, end);
        return root;
    }


    TreeNode* sortedListToBST(ListNode* head) {
        return maketree(head, nullptr); // 不应该修改链表，而是给出要处理的链表的终止。默认为null
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-10,-3,0,5,9]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

