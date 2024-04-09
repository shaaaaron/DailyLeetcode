/*
 * @lc app=leetcode.cn id=94 lang=cpp
 * @lcpr version=30121
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* curr=nullptr; // 初始化
        vector<int> ans;

        // if(root==nullptr) return ans;
        // st.push(root);
        curr=root; // 不能使用st初始化，而是使用curr初始化。因为要把root左边的全部按顺序入栈，如果st初始化会首先访问st.top元素而出错

        while(curr!=nullptr || !st.empty()){
            if(curr != nullptr){ // 默认一直向左
                st.push(curr);
                curr=curr->left;
            }else{
                TreeNode* stTop=st.top();
                st.pop();

                ans.push_back(stTop->val);  // 访问中间节点
                curr=stTop->right;          // curr置为right
            }
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2]\n
// @lcpr case=end
// @lcpr case=start
// [1,null,2,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

