#
# @lc app=leetcode.cn id=24 lang=python
# @lcpr version=30121
#
# [24] 两两交换链表中的节点
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        fakehead= ListNode(0, head)
        before = fakehead
        curr = before.next

        while before.next is not None and before.next.next is not None:
            curr = before.next
            behind = curr.next

            before.next=curr.next
            curr.next=behind.next
            behind.next=curr

            before=before.next.next
        return fakehead.next

        
# @lc code=end



#
# @lcpr case=start
# [1,2,3,4]\n
# @lcpr case=end

# @lcpr case=start
# []\n
# @lcpr case=end

# @lcpr case=start
# [1]\n
# @lcpr case=end

#

