#
# @lc app=leetcode.cn id=108 lang=python
# @lcpr version=30122
#
# [108] 将有序数组转换为二叉搜索树
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
    def dfs(self, lo, hi):
        if hi<=lo:
            return None
        
        # 每次严格递减，对长度为1不需要特殊处理
        mid = (lo+hi)//2
        root = TreeNode(self.nums[mid])
        root.left = self.dfs(lo, mid)
        root.right = self.dfs(mid+1, hi)
        return root
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        self.nums = nums
        return self.dfs(0, len(nums))
        
# @lc code=end



#
# @lcpr case=start
# [-10,-3,0,5,9]\n
# @lcpr case=end

# @lcpr case=start
# [1,3]\n
# @lcpr case=end
# @lcpr case=start
# [1]\n
# @lcpr case=end

#

