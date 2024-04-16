#
# @lc app=leetcode.cn id=222 lang=python
# @lcpr version=30122
#
# [222] 完全二叉树的节点个数
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
def count_level(root):  # 简单的功能
    ans = 0
    while root is not None:
        ans+=1
        root=root.left

    return ans
    
class Solution(object):
    def countNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        
        left_depth = count_level(root.left)
        right_depth = count_level(root.right)

        if left_depth == right_depth:   
            return (1<<left_depth) + self.countNodes(root.right)    #   位运算的优先级非常低
                                                                    # 使用(1<<left_depth)计算过程中就包含了根节点
        else:
            return (1<<right_depth) + self.countNodes(root.left)
        
# @lc code=end



#
# @lcpr case=start
# [1,2,3,4,5,6]\n
# @lcpr case=end

# @lcpr case=start
# []\n
# @lcpr case=end

# @lcpr case=start
# [1]\n
# @lcpr case=end

#

