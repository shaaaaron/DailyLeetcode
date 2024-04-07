#
# @lc app=leetcode.cn id=142 lang=python
# @lcpr version=30121
#
# [142] 环形链表 II
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        slow, fast=head, head
        while fast is not None and fast.next is not None:
            slow=slow.next
            fast=fast.next.next
            if fast is slow:
                tmp=head
                while True:
                    if tmp is fast:
                        return tmp
                    tmp=tmp.next
                    fast=fast.next
        return None

# @lc code=end



#
# @lcpr case=start
# [3,2,0,-4]\n1\n
# @lcpr case=end

# @lcpr case=start
# [1,2]\n0\n
# @lcpr case=end

# @lcpr case=start
# [1]\n-1\n
# @lcpr case=end

#

