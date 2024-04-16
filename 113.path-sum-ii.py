#
# @lc app=leetcode.cn id=113 lang=python
# @lcpr version=30122
#
# [113] 路径总和 II
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
    def dfs(self, root, pre_sum, pre_path, targetSum):
        # 遍历到叶子节点而不是空节点
        now_sum = pre_sum + root.val
        now_path = pre_path + [root.val]

        if root.left is None and root.right is None:
            if now_sum == targetSum:
                self.ans.append(now_path)
            return

            
        
        if root.left is not None:
            self.dfs(root.left, now_sum, now_path, targetSum)

        if root.right is not None:
            self.dfs(root.right, now_sum, now_path, targetSum)

        

    def pathSum(self, root, targetSum):
        """
        :type root: TreeNode
        :type targetSum: int
        :rtype: List[List[int]]
        """
        if root is None:
            return []
        
        self.ans=[]
        self.dfs(root, 0, [], targetSum)
        return self.ans

        
# @lc code=end



#
# @lcpr case=start
# [5,4,8,11,null,13,4,7,2,null,null,5,1]\n22\n
# @lcpr case=end

# @lcpr case=start
# [1,2,3]\n5\n
# @lcpr case=end

# @lcpr case=start
# [1,2]\n0\n
# @lcpr case=end

#

