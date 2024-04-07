#
# @lc app=leetcode.cn id=2 lang=python
# @lcpr version=30121
#
# [2] 两数相加
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
# Definition for singly-linked list.
def myadd(x, y):
    return (1, x+y-10) if x+y>=10 else (0,x+y)

class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        # head1,head2 = ListNode(0, l1), ListNode(0, l2)
        head=ListNode(0)

        before=head
        tmp=0 # 进位
        while l1 is not None or l2 is not None:
            if l1 is not None and l2 is not None:
                tmp, tmp2=myadd(l1.val, l2.val+tmp)

                before.next= ListNode(tmp2)
                before, l1, l2=before.next, l1.next, l2.next
            elif l1 is None and l2 is not None:
                (tmp, tmp2)=myadd(0, l2.val+tmp)
                before.next= ListNode(tmp2)
                before, l2=before.next, l2.next
            elif l1 is not None and l2 is None:
                (tmp, tmp2)=myadd(l1.val, tmp)
                before.next= ListNode(tmp2)
                l1, before=l1.next, before.next

        if tmp!=0:
            before.next= ListNode(tmp)
        return head.next
# @lc code=end



#
# @lcpr case=start
# [2,4,3]\n[5,6,4]\n
# @lcpr case=end

# @lcpr case=start
# [0]\n[0]\n
# @lcpr case=end

# @lcpr case=start
# [9,9,9,9,9,9,9]\n[9,9,9,9]\n
# @lcpr case=end

#

