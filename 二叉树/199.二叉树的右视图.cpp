/*
 * @lc app=leetcode.cn id=199 lang=cpp
 * @lcpr version=30121
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        deque<TreeNode*> dq;

        if(root==nullptr) return ans; // 检查是否为空
        dq.push_back(root);
        while(!dq.empty()){
            int qsize=dq.size();

            for(int i=1;i<=qsize;i++){
                TreeNode* front=dq.front();
                dq.pop_front();

                if(front->left) dq.push_back(front->left);
                if(front->right) dq.push_back(front->right);
                if(i==qsize) ans.push_back(front->val);
            }
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,null,5,null,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

