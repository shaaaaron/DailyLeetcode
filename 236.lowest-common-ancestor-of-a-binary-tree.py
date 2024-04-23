#
# @lc app=leetcode.cn id=236 lang=python
# @lcpr version=30122
#
# [236] 二叉树的最近公共祖先
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def dfs(self, r, p, q):
        # 使用后序遍历，用ans记录第一次满足条件的.
        # 虽然是从上向下遍历，但是后序，记录第一次出现的
        # 标准答案有点奇怪
        if r is None:
            return 0
        
        result = 0 
        result+=self.dfs(r.left, p, q)
        result+=self.dfs(r.right, p, q)
        if r.val==p:
            result+=1
        if r.val==q:
            result+=2
        
        if result==3 and self.ans is None:
            self.ans=r  # 返回的是节点不是val，返回val会导致判题器报错

        return result
    
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        self.ans = None
        self.dfs(root, p.val, q.val)
        return self.ans
        
# @lc code=end



#
# @lcpr case=start
# [3,5,1,6,2,0,8,null,null,7,4]\n5\n1\n
# @lcpr case=end

# @lcpr case=start
# [3,5,1,6,2,0,8,null,null,7,4]\n5\n4\n
# @lcpr case=end

# @lcpr case=start
# [1,2]\n1\n2\n
# @lcpr case=end

#

