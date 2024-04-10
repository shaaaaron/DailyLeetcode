/*
 * @lc app=leetcode.cn id=100 lang=cpp
 * @lcpr version=30121
 *
 * [100] 相同的树
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}  
};

class Solution {
public:
    // bool isSameTree(TreeNode* p, TreeNode* q) {
    //     if(!p && !q) return true;
    //     if(p && !q || !p && q) return false;
    //     if(p->val==q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right)){
    //         return true;
    //     }

    //     return false;
    // }

    bool isSameTree(TreeNode* root1, TreeNode* root2) {
        // 同时用非递归的dfs遍历两个节点
        if(!root1 && !root2) return true;
        if(!root1&&root2 || root1&&!root2) return false;

        stack<TreeNode*> st1,st2;
        st1.push(root1);
        st2.push(root2);

        while(!st1.empty()){ // st1和st2中元素数量时相同的
            TreeNode *curr1=st1.top(), *curr2=st2.top();
            st1.pop();
            st2.pop();

            // 栈中元素非空
            if(curr1->val != curr2->val) return false;
            if(curr1->left && !curr2->left || !curr1->left && curr2->left) return false;
            if(curr1->right && !curr2->right || !curr1->right && curr2->right) return false;

            // left同时为空或不为空，right同理
            if(curr1->left){
                st1.push(curr1->left);
                st2.push(curr2->left);
            }
            if(curr1->right){
                st1.push(curr1->right);
                st2.push(curr2->right);
            }
        }

        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n[1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[1,null,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,1]\n[1,1,2]\n
// @lcpr case=end

 */

