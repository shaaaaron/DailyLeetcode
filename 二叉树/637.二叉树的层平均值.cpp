/*
 * @lc app=leetcode.cn id=637 lang=cpp
 * @lcpr version=30121
 *
 * [637] 二叉树的层平均值
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(root==nullptr) return ans;

        deque<TreeNode*> dq;
        dq.push_back(root);

        while(!dq.empty()){
            int qsize=dq.size();
            double sum=0;
            for(int i=1;i<=qsize;i++){
                TreeNode* front=dq.front();
                dq.pop_front();
                sum+=front->val;

                if(front->left)dq.push_back(front->left);
                if(front->right)dq.push_back(front->right);
            }
            ans.push_back(sum/qsize);
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
// [3,9,20,15,7]\n
// @lcpr case=end


 */

