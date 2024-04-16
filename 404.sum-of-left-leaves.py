#
# @lc app=leetcode.cn id=404 lang=python
# @lcpr version=30122
#
# [404] 左叶子之和
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def dfs(self, root, left_or_not):    # left表示当前节点是左节点。记录当前子树的左叶子之和。必须要从上一层的状态判断是不是左叶子节点
        # 遍历到叶子节点的时候更新，而不是空节点
        if root.left is None and root.right is None:
            return root.val if left_or_not else 0
        
        # 如果不是叶子节点，则对左右进行计算
        ans = 0
        if root.left is not None:
            ans += self.dfs(root.left, True)
        if root.right is not None:
            ans += self.dfs(root.right, False)

        return ans
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        # 本题中根节点不视为叶子节点
        return self.dfs(root, False)
# @lc code=end



#
# @lcpr case=start
# [3]\n
# @lcpr case=end

# @lcpr case=start
# [3,9,20,null,null,15,7]\n
# @lcpr case=end

# @lcpr case=start
# [1]\n
# @lcpr case=end

#

