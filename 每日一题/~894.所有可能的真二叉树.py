#
# @lc app=leetcode.cn id=894 lang=python
# @lcpr version=30121
#
# [894] 所有可能的真二叉树
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
# Definition for a binary tree node.
import copy

# 尝试一下递归的做法
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def allPossibleFBT(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        if n%2==0:
            return []
        
        dp = [[] for _ in range(0, n+1)]    # 注意dp的使用方法，是将dp[i]和dp[n-i-1]作为根节点的左右两个子节点
        # dp[n]的构造从根节点（顶部开始），而不是底部
        dp[1]=[TreeNode()]

        # 对i j的循环可以优化，但是第一次实现的时候简单为要，不需要扣小地方
        # j是遍历到i而不是n
        for i in range(2, n+1):
            # for j in range(i): # 到i-1
            for j in range(1, i, 2): # 改为这行适当提高性能
                k=i-j-1
                for leftNode in dp[j]:
                    for rightNode in dp[k]:
                        # dp[i].append(TreeNode(0, copy.deepcopy(leftNode), copy.deepcopy(rightNode)))
                        dp[i].append(TreeNode(0, (leftNode), (rightNode)))  # 按理使用深拷贝，但是leetcode这题没要求，所以浅拷贝大幅提升速度和内存
        
        return dp[n]
# @lc code=end


#
# @lcpr case=start
# 8\n
# @lcpr case=end
# @lcpr case=start
# 7\n
# @lcpr case=end

# @lcpr case=start
# 3\n
# @lcpr case=end

#

