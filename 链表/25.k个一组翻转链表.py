#
# @lc app=leetcode.cn id=25 lang=python
# @lcpr version=30121
#
# [25] K 个一组翻转链表
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
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        fakehead = ListNode(0, head)
        before = fakehead

        while True:
            step=k
            end=before
            while step>0:
                step-=1
                end=end.next
                if end is None:
                    return fakehead.next    # 不能使用错误
            tmp=before.next

            tmp3, slow, fast=end.next, end.next, before.next
            while  fast is not tmp3:
                # print(fakehead)
                tmp2=fast.next

                fast.next=slow
                fast, slow=tmp2, fast
            before.next=slow
            before=tmp
        
# @lc code=end



#
# @lcpr case=start
# [1,2,3,4,5,6,7]\n1\n
# @lcpr case=end

# @lcpr case=start
# [1,2,3,4,5]\n3\n
# @lcpr case=end

#

