/*
 * @lc app=leetcode.cn id=104 lang=cpp
 * @lcpr version=30121
 *
 * [104] 二叉树的最大深度
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
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;

        deque<TreeNode*> dq;
        dq.push_back(root);

        int depth=0; // 初始化,root默认为1
        while(!dq.empty()){
            depth++;
            int qsize=dq.size();
            for(int i=1;i<=qsize;i++){
                TreeNode* front=dq.front();
                dq.pop_front();

                if(front->left)dq.push_back(front->left);
                if(front->right)dq.push_back(front->right);
            }
        }

        return depth;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,2]\n
// @lcpr case=end

 */

