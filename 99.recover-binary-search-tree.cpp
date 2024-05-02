/*
 * @lc app=leetcode.cn id=99 lang=cpp
 * @lcpr version=30122
 *
 * [99] 恢复二叉搜索树
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
    bool flag;
    TreeNode *x, *y,* before;

    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        if(before!= nullptr && before->val>root->val){
            if(flag==false){
                flag=true;
                x=before;
                y=root; // 特殊处理
            }else{
                y=root;
            }
        }
        before=root;
        dfs(root->right);
    }

    // 本质是按顺序遍历（中序遍历），找到相邻逆序对
    // 如果一个和两个，分别处理
    // x，y记录节点而不是值，否则需要遍历两次
    void recoverTree(TreeNode* root) {
        flag=false;
        before=nullptr;
        dfs(root);
        swap(x->val, y->val);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,null,null,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,1,4,null,null,2]\n
// @lcpr case=end

 */

