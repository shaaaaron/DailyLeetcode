/*
 * @lc app=leetcode.cn id=515 lang=cpp
 * @lcpr version=30121
 *
 * [515] 在每个树行中找最大值
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr)return ans;

        deque<TreeNode*> dq;
        dq.push_back(root);
        while(!dq.empty()){
            int qsize=dq.size();
            int maxval=INT_MIN;
            for(int i=0;i<qsize;i++){
                TreeNode* curr=dq.front();
                if(curr->val>=maxval)   maxval=curr->val;
                if(curr->left) dq.push_back(curr->left);
                if(curr->right) dq.push_back(curr->right);
                dq.pop_front();
            }

            ans.push_back(maxval);
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,2,5,3,null,9]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */

