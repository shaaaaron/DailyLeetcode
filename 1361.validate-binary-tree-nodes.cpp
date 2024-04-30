/*
 * @lc app=leetcode.cn id=1361 lang=cpp
 * @lcpr version=30122
 *
 * [1361] 验证二叉树
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
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> node_in(n);
        for(int i=0;i<n;i++){
            if(leftChild[i]!=-1)
                node_in[leftChild[i]]++;
            if(rightChild[i]!=-1) 
                node_in[rightChild[i]]++; 
        }
        
        int zero_idx=-1;
        for(int i=0;i<n;i++){
            if(node_in[i]>=2) return false;
            if(node_in[i]==0){
                if(zero_idx==-1){
                    zero_idx=i;
                }else
                    return false;
            }
        }
        if(zero_idx==-1) return false;
        
        queue<int> q;
        q.push(zero_idx);
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            if(leftChild[cur]!=-1){
                node_in[leftChild[cur]]--;
                if(node_in[leftChild[cur]]==0)
                    q.push(leftChild[cur]);
            }
            if(rightChild[cur]!=-1){
                node_in[rightChild[cur]]--;
                if(node_in[rightChild[cur]]==0)
                    q.push(rightChild[cur]);
            }
        }
        for(int num:node_in){
            if(num) return false;
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n[1,-1,3,-1]\n[2,-1,-1,-1]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[1,-1,3,-1]\n[2,3,-1,-1]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[1,0]\n[-1,-1]\n
// @lcpr case=end

 */

