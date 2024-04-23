#
# @lc app=leetcode.cn id=450 lang=python
# @lcpr version=30122
#
# [450] 删除二叉搜索树中的节点
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
    def deleteNode(self, root, key):
        """
        :type root: TreeNode
        :type key: int
        :rtype: TreeNode
        """
        fake_head = TreeNode(0, root) # 虚拟节点

        pre = fake_head
        pre_tmp_dir = True      # true表示左方向
        tmp = root

        while tmp is not None:
            if tmp.val==key:
                if tmp.left is None and tmp.right is None:
                    if pre_tmp_dir:
                        pre.left=None
                    else:
                        pre.right=None
                elif tmp.left is None:
                    if pre_tmp_dir:
                        pre.left=tmp.right
                    else:
                        pre.right=tmp.right
                elif tmp.right is None:
                    if pre_tmp_dir:
                        pre.left=tmp.left
                    else:
                        pre.right=tmp.left
                else:
                    if tmp.right.left is None:
                        tmp.val = tmp.right.val
                        tmp.right = tmp.right.right
                    else:
                        child_pre,child_cur = tmp.right, tmp.right.left
                        while child_cur.left is not None:
                            child_pre=child_cur
                            child_cur=child_cur.left
                        # child_pre.left=None
                        child_pre.left = child_cur.right    # 不能漏掉半边子树
                        tmp.val = child_cur.val

                return fake_head.left # 可能删除头节点，所以应该返回fakehead后面的，而不是root
            elif tmp.val<key:
                pre=tmp
                tmp=tmp.right
                pre_tmp_dir=False
            else:
                pre=tmp
                tmp=tmp.left
                pre_tmp_dir=True
        
        return root
# @lc code=end



#
# @lcpr case=start
# [0]\n0\n
# @lcpr case=end
# @lcpr case=start
# [5,3,6,2,4,null,7]\n3\n
# @lcpr case=end

# @lcpr case=start
# [5,3,6,2,4,null,7]\n0\n
# @lcpr case=end

# @lcpr case=start
# []\n0\n
# @lcpr case=end
# @lcpr case=start
# [3,2,5,null,null,4,10,null,null,8,15,7]\n5\n
# @lcpr case=end

#

