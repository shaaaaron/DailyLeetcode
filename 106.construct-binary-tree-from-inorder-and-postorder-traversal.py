#
# @lc app=leetcode.cn id=106 lang=python
# @lcpr version=30122
#
# [106] 从中序与后序遍历序列构造二叉树
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
# Definition for a binary tree node.

# 前序和中序遍历可以确定二叉树，后序和中序可以确定二叉树
# 但是前序和后序遍历无法构建二叉树
# 详情见[这里](https://www.programmercarl.com/0106.%E4%BB%8E%E4%B8%AD%E5%BA%8F%E4%B8%8E%E5%90%8E%E5%BA%8F%E9%81%8D%E5%8E%86%E5%BA%8F%E5%88%97%E6%9E%84%E9%80%A0%E4%BA%8C%E5%8F%89%E6%A0%91.html#%E6%80%9D%E8%80%83%E9%A2%98)
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def dfs(self, i_start, i_end, p_start, p_end):
        assert i_end-i_start == p_end-p_start

        if i_start>=i_end:  # 
            return None # 而不是TreeNode
        if i_start+1 == i_end:
            return TreeNode(self.inorder[i_start])
        
        # 区间至少有两个元素
        root_val = self.postorder[p_end-1]
        root = TreeNode(self.postorder[p_end-1])    # 后续遍历最后一额是root val

        inorder_index=i_start
        while inorder_index < i_end:
            if self.inorder[inorder_index] == root_val:
                break
            inorder_index+=1

        postorder_index=inorder_index- i_start + p_start    # 起始位置不同

        root.left = self.dfs(i_start, inorder_index, p_start, postorder_index)  # 注意区间的开闭
        root.right = self.dfs(inorder_index+1, i_end, postorder_index, p_end-1)

        return root

        
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        # 保证所有节点的值都不相同
        self.inorder = inorder
        self.postorder = postorder
        root = self.dfs(0, len(inorder), 0, len(inorder))
        return root
# @lc code=end



#
# @lcpr case=start
# [2,1]\n[2,1]\n
# @lcpr case=end
# @lcpr case=start
# [9,3,15,20,7]\n[9,15,7,20,3]\n
# @lcpr case=end

# @lcpr case=start
# [-1]\n[-1]\n
# @lcpr case=end

#

