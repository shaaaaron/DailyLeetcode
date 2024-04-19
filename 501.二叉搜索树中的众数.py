#
# @lc app=leetcode.cn id=501 lang=python
# @lcpr version=30122
#
# [501] 二叉搜索树中的众数
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
        
        self.dfs(root.left)
        if self.last_val is None or root.val==self.last_val:
            # 如果数值相同
            self.now_count+=1
        else:
            self.now_count=1
        self.last_val=root.val  # 难崩，赋值和等于

        if self.now_count>self.max_count:
            self.max_count=self.now_count
            self.ans_lst=[root.val]
        elif self.now_count == self.max_count:
            self.ans_lst.append(root.val)


        self.dfs(root.right)

    def findMode(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        self.last_val, self.now_count=None, 0
        self.ans_lst, self.max_count=[], 0
        self.dfs(root)

        return self.ans_lst
        
# @lc code=end



#
# @lcpr case=start
# [1,null,2]\n
# @lcpr case=end
# @lcpr case=start
# [1,null,2,2]\n
# @lcpr case=end

# @lcpr case=start
# [0]\n
# @lcpr case=end

#

