#
# @lc app=leetcode.cn id=701 lang=python
# @lcpr version=30122
#
# [701] 二叉搜索树中的插入操作
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution(object):
    def insertIntoBST(self, root, val):
        """
        :type root: TreeNode
        :type val: int
        :rtype: TreeNode
        """
        if root is None:
            return TreeNode(val)
        
        # 保证dfs时root不为空
        if root.val<val:
            if root.right is None:
                root.right = TreeNode(val)
            else:
                self.insertIntoBST(root.right, val)
        else:
            if root.left is None:
                root.left = TreeNode(val)
            else:
                self.insertIntoBST(root.left, val)
        
        return root
# @lc code=end



#
# @lcpr case=start
# [4,2,7,1,3]\n5\n
# @lcpr case=end

# @lcpr case=start
# [40,20,60,10,30,50,70]\n25\n
# @lcpr case=end

# @lcpr case=start
# [4,2,7,1,3,null,null,null,null,null,null]\n5\n
# @lcpr case=end

#

