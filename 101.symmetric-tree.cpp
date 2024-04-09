/*
 * @lc app=leetcode.cn id=101 lang=cpp
 * @lcpr version=30121
 *
 * [101] 对称二叉树
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


// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    bool checkPointerNullConflict(TreeNode *a, TreeNode *b){
        if(!a && !b) return false;
        if(!a&&b || a&&!b) return true;
        return false;   // true表示矛盾，fasle表示目前不知道是否慢炖
                        // 但是ab同时为空或者非空
    };

    bool isSymmetric(TreeNode* root) {
        deque<TreeNode*> dq;
        if(!root->left && !root->right)return true;
        if(!root->left && root->right)return false;
        if(root->left && !root->right)return false;

        dq.push_back(root->left);
        dq.push_back(root->right);

        while(!dq.empty()){
            TreeNode* left=dq.front();    dq.pop_front();
            TreeNode* right=dq.front();   dq.pop_front();

            // 栈中元素保证不是空的
            if(left->val != right->val) return false;

            TreeNode *tmp1=left->right, *tmp2=right->left;
            if(checkPointerNullConflict(tmp1, tmp2)) return false;
            if(tmp1){
                dq.push_back(tmp1);
                dq.push_back(tmp2);
            }
            
            tmp1=left->left; tmp2=right->right;
            if(checkPointerNullConflict(tmp1, tmp2)) return false;
            if(tmp1){
                dq.push_back(tmp1);
                dq.push_back(tmp2);
            }
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,2,3,4,4,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,null,3,null,3]\n
// @lcpr case=end

 */

