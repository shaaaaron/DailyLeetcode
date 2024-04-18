/*
 * @lc app=leetcode.cn id=968 lang=cpp
 * @lcpr version=30122
 *
 * [968] 监控二叉树
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
//在树上进行dp，
    // tuple<int,int> dp(TreeNode* root){
    //     if(root==nullptr) return {0,0};
    //     if(root->left==nullptr && root->right==nullptr) return {1,0};
    //     // if(root->left==nullptr && root->right!=nullptr){
    //     //     auto [node_r, no_node_r] = dp(root->right); // 结构化绑定
    //     //     return {no_node_r+1, node_r};
    //     // } 
    //     // if(root->left!=nullptr && root->right==nullptr){
    //     //     auto [node_l, no_node_l] = dp(root->left); // 结构化绑定
    //     //     return {no_node_l+1, node_l};
    //     // } 

    //     // 下面是左右都非空，否则
    //     auto [node_l, no_node_l] = dp(root->left); // 前者最高为监控，后者最高不为
    //     // 和打家劫舍不同，打家劫舍是不能两个相邻，这里两个至少有一个
    //     auto [node_r, no_node_r] = dp(root->right); // 结构化绑定
        
    //     return {1+no_node_l+no_node_r, node_l+node_r}; //pair和tuple都可以直接写成方括号构造
    // }
    // 上面的代码有问题，如果三个相邻，会101安装两个

    // 应该按下面分解为三个状态，进行dp
    // 分为三个状态是因为，对于一个节点有三种方法被监控
    tuple<int,int,int> dp(TreeNode* root){
        if(root==nullptr) return {INT_MAX/2,0,0}; // 需要除2防止溢出。由于后面min操作，一定不会有超过两个intmin/2相加
        // 空节点不能安装摄像头，安装的代价是无穷高。防止空节点的父节点通过空节点来不安装摄像头。被父亲和儿子监控则不影响
        auto[ l_choose, l_by_father, l_by_son] = dp(root->left);
        auto[ r_choose, r_by_father, r_by_son] = dp(root->right);

        int choose=min(l_choose, min(l_by_father, l_by_son))+min(r_choose, min(r_by_father, r_by_son)) +1; // 当前节点被选择  的最小节点数
        int by_father=min(l_choose, l_by_son)+min(r_choose, r_by_son); //
        // 当前节点没有被选择，而是被fa监控
        int by_son=min( l_choose+r_choose, min(l_choose+r_by_son, l_by_son+r_choose));
        // 当前节点没有被选择，而是被son监控
        // 一个节点既可以是黄色也可以是红色。多种情况可能有重叠！

        return {choose, by_father, by_son};
    }

    int minCameraCover(TreeNode* root) {
        auto [choose, _, by_son] = dp(root);
        return min(choose, by_son);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,0,null,0,0]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,null,0,null,0,null,null,0]\n
// @lcpr case=end

 */

