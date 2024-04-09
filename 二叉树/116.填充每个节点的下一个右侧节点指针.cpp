/*
 * @lc app=leetcode.cn id=116 lang=cpp
 * @lcpr version=30121
 *
 * [116] 填充每个节点的下一个右侧节点指针
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
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) { // 使用bfs解决这个问题
        if(root==nullptr) return root;

        deque<Node*> dq;
        dq.push_back(root);

        while(!dq.empty()){
            int qsize=dq.size();

            for(int i=1;i<=qsize;i++){
                Node* front=dq.front();
                dq.pop_front();
                
                front->next= i!=qsize ?dq.front():nullptr;
                if(front->left)dq.push_back(front->left);
                if(front->right)dq.push_back(front->right);
            }
        }

        return root;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5,6,7]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

