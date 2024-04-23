#
# @lc app=leetcode.cn id=530 lang=python
# @lcpr version=30122
#
# [530] 二叉搜索树的最小绝对差
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
    def dfs(self, root):
        if root is None:
            return 
        # 二叉搜索树使用中序遍历，恰好是从小到大遍历
        self.dfs(root.left)

        if self.last is not None:
            if self.ans is None:
                self.ans = abs(root.val-self.last)
            else:
                self.ans = min(self.ans, abs(root.val-self.last))    # abs可以返回int或者float
        self.last = root.val

        self.dfs(root.right)

    def getMinimumDifference(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        # 至少有两个节点
        
        self.last, self.ans = None, None
        self.dfs(root)
        return self.ans
        
# @lc code=end



#

# @lcpr case=start
# [4,2,6,1,3]\n
# @lcpr case=end

# @lcpr case=start
# [1,0,48,null,null,12,49]\n
# @lcpr case=end

#

