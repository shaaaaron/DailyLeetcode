/*
 * @lc app=leetcode.cn id=144 lang=cpp
 * @lcpr version=30121
 *
 * [144] 二叉树的前序遍历
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
    // vector<int> preorderTraversal(TreeNode* root) {
    //     if(root==nullptr)return vector<int> {};

    //     vector<int> ans{root->val};
    //     vector<int> left=preorderTraversal(root->left);
    //     vector<int> right=preorderTraversal(root->right);
    //     ans.insert(ans.end(),left.begin(),left.end());
    //     ans.insert(ans.end(),right.begin(),right.end());

    //     return ans;
    // }

    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        if(root==nullptr) return vector<int>{};
        
        vector<int>ans;
        st.push(root);
        while(!st.empty()){
            TreeNode* curr=st.top();
            st.pop();
            ans.push_back(curr->val);

            TreeNode *left=curr->left, *right=curr->right;
            if(right!=nullptr)  st.push(right); // 注意右边的先进栈，后执行
            if(left!=nullptr)   st.push(left);
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,1,2]\n
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

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,2]\n
// @lcpr case=end

 */

