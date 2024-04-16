#
# @lc app=leetcode.cn id=513 lang=python
# @lcpr version=30122
#
# [513] 找树左下角的值
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
from collections import deque

class Solution(object):
    def findBottomLeftValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        dq = deque()
        ans = None  # 遍历完才知道最后一层是什么，因为用ans存最后更新的答案
        # 至少有根节点，非空才进队列
        dq.append(root)

        while(len(dq)>0):
            qsize = len(dq)
            for i in range(qsize):
                if i==0:
                    ans = dq[0].val

                if dq[0].left is not None:
                    dq.append(dq[0].left)
                if dq[0].right is not None:
                    dq.append(dq[0].right)
                dq.popleft()

        return ans
        
# @lc code=end



#
# @lcpr case=start
# [2,1,3]\n
# @lcpr case=end

# @lcpr case=start
# [1,2,3,4,null,5,6,null,null,7]\n
# @lcpr case=end

#

