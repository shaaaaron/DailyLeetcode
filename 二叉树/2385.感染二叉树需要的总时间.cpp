/*
 * @lc app=leetcode.cn id=2385 lang=cpp
 * @lcpr version=30122
 *
 * [2385] 感染二叉树需要的总时间
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
    TreeNode * find_start(TreeNode *root, int val){
        if(root==nullptr) return nullptr;
        if(root->val==val) return root;

        TreeNode* tmp=find_start(root->left, val);
        if(tmp!=nullptr) return tmp;
        tmp=find_start(root->right, val); //rede
        if(tmp!=nullptr) return tmp;

        return nullptr;
    }

    void find_father(TreeNode* root, unordered_map<int, TreeNode *>&memo){
        // 保证root不是空节点
        // 遍历到r的时候处理子节点
        if(root->left !=nullptr){
            memo[root->left->val]=root;
            find_father(root->left, memo);
        }

        if(root->right !=nullptr){
            memo[root->right->val]=root;
            find_father(root->right, memo);
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        // 节点大小互不相同，首先找到爆发节点
        TreeNode * start_node=find_start(root, start);
        // cout<<"start_node"<<start_node->val;

        unordered_map<int, TreeNode *> memo;
        find_father(root, memo);

        // 使用bfs进行遍历
        unordered_map<TreeNode *, int> vis;
        deque<TreeNode* >dq;

        dq.push_back(start_node);
        vis[start_node]++;

        int ans=0;
        while(!dq.empty()){
            int qsize=dq.size();
            for(int i=0;i<qsize;i++){
                TreeNode* cur=dq.front();
                dq.pop_front();

                if(cur->left!=nullptr && vis.find(cur->left)==vis.end()){
                    vis[cur->left]++;
                    dq.push_back(cur->left);
                }
                
                if(cur->right!=nullptr && vis.find(cur->right)==vis.end()){
                    vis[cur->right]++;
                    dq.push_back(cur->right);
                }

                if(memo.find(cur->val)!=memo.end() && vis.find(memo.at(cur->val))==vis.end()){
                    vis[memo.at(cur->val)]++;
                    dq.push_back(memo.at(cur->val));
                }
            }
            ans++;
        }
        
        return ans-1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,5,3,null,4,10,6,9,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */

