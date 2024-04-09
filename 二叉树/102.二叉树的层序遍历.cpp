/*
 * @lc app=leetcode.cn id=102 lang=cpp
 * @lcpr version=30121
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        deque<TreeNode*> dq;

        if(root==nullptr)return ans;
        
        dq.push_back(root);
        while(!dq.empty()){
            int qsize=dq.size();
            vector<int> tmpList;
            for(int i=0;i<qsize;i++){
                TreeNode* curr=dq.front();
                tmpList.push_back(curr->val);
                if(curr->left) dq.push_back(curr->left);
                if(curr->right) dq.push_back(curr->right);
                dq.pop_front();
            }

            ans.push_back(tmpList);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

