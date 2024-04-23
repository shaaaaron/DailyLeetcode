#
# @lc app=leetcode.cn id=235 lang=python
# @lcpr version=30122
#
# [235] 二叉搜索树的最近公共祖先
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
    # 二叉搜索树的最左边和最右边的节点是最小的和最大的，dfs可以获得子树的范围
    def dfs(self, r, p_val, q_val):
        # dfs时保证不是空节点
        tmp=[r.val, r.val]
        if r.left is not None:
            tmp[0]=self.dfs(r.left, p_val, q_val)[0]
        if r.right is not None:
            tmp[1]=self.dfs(r.right, p_val, q_val)[1]

        if self.ans is None:
            if tmp[0]<=p_val<=tmp[1] and  tmp[0]<=q_val<=tmp[1]:
                self.ans = r
        # print(r.val, tmp)
        return tmp
                

    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        self.ans=None
        self.dfs(root, p.val, q.val)
        return self.ans
# @lc code=end



#
# @lcpr case=start
# [6,2,8,0,4,7,9,null,null,3,5]\n2\n8\n
# @lcpr case=end

# @lcpr case=start
# [6,2,8,0,4,7,9,null,null,3,5]\n2\n4\n
# @lcpr case=end

#

