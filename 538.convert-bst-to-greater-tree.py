#
# @lc app=leetcode.cn id=538 lang=python
# @lcpr version=30122
#
# [538] 把二叉搜索树转换为累加树
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
    # 由于二叉搜索树是顺序的，所以挑选合适的顺序进行遍历
    def dfs(self, r):
        if r is None:
            return 
        
        self.dfs(r.right)
        r.val+=self.before_sum
        self.before_sum=r.val
        self.dfs(r.left)
    def convertBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        self.before_sum=0
        self.dfs(root)
        return root
        
# @lc code=end



#
# @lcpr case=start
# [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]\n
# @lcpr case=end

# @lcpr case=start
# [0,null,1]\n
# @lcpr case=end

# @lcpr case=start
# [1,0,2]\n
# @lcpr case=end

# @lcpr case=start
# [3,2,4,1]\n
# @lcpr case=end

#

