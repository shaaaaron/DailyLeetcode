/*
 * @lc app=leetcode.cn id=145 lang=cpp
 * @lcpr version=30121
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        if(root==nullptr)return vector<int>{};

        st.push(root);
        vector<int> ans;
        // 后序遍历是左右中，反过来是中右左
        while(!st.empty()){
            TreeNode* curr=st.top();
            st.pop();

            ans.push_back(curr->val);
            if(curr->left!=nullptr) st.push(curr->left);
            if(curr->right!=nullptr) st.push(curr->right);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end



/*
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

