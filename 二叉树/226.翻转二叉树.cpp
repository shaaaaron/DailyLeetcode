/*
 * @lc app=leetcode.cn id=226 lang=cpp
 * @lcpr version=30121
 *
 * [226] 翻转二叉树
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
class Solution {
public:
    // TreeNode* invertTree(TreeNode* root) {
    //     if(root==nullptr) return root;

    //     TreeNode* tmp=root->left;
    //     root->left=root->right;
    //     root->right=tmp;

    //     invertTree(root->left);
    //     invertTree(root->right);

    //     return root;
    // }
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr) return root;
        
        stack<TreeNode*> st;
        st.push(root);

        
        TreeNode* curr, *tmp;
        while(!st.empty()){
            curr=st.top();
            st.pop();

            tmp=curr->left;
            curr->left=curr->right;
            curr->right=tmp;

            if(curr->left) st.push(curr->left);
            if(curr->right) st.push(curr->right);
        }
        return root;
    }

};
// @lc code=end



/*
// @lcpr case=start
// [4,2,7,1,3,6,9]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

