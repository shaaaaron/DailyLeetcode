#
# @lc app=leetcode.cn id=19 lang=python
# @lcpr version=30121
#
# [19] 删除链表的倒数第 N 个结点
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        fakehead=ListNode(0,head)

        before=fakehead
        behind=fakehead.next.next
        n-=1
        while n>0:
            n-=1
            behind=behind.next

        while True:
            if behind is None:
                curr=before.next
                before.next=curr.next
                return fakehead.next
            
            before=before.next
            behind=behind.next

        return fakehead.next
        
# @lc code=end



#
# @lcpr case=start
# [1,2,3,4,5]\n2\n
# @lcpr case=end

# @lcpr case=start
# [1]\n1\n
# @lcpr case=end

# @lcpr case=start
# [1,2]\n1\n
# @lcpr case=end

#

