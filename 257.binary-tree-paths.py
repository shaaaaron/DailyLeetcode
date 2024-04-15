#
# @lc app=leetcode.cn id=257 lang=python
# @lcpr version=30122
#
# [257] 二叉树的所有路径
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
    def dfs(self, root, pre_path):
        # dfs保存好自己的状态，每一步进行计算，在递归终止时加入ans
        now_path = str(root.val) if pre_path=="" else pre_path+"->"+ str(root.val) # 传引用，不应该修改
        # 统一计算，不用后面计算
        # leetcode python不支持f字符串,python3支持

        # 为了防止重复计算，在遍历到叶子节点的时候添加路径，而不是空节点添加路径
        if root.left is None and root.right is None:
            self.ans.append(now_path)
            return
        
        if root.left is not None:   # 非空才访问
            self.dfs(root.left, now_path)
        if root.right is not None:
            self.dfs(root.right, now_path)

        

    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        self.ans = []
        self.dfs(root, "")  # 至少存在一个节点

        return self.ans
        
# @lc code=end



#
# @lcpr case=start
# [1,2,3,null,5]\n
# @lcpr case=end

# @lcpr case=start
# [1]\n
# @lcpr case=end

#

