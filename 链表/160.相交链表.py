#
# @lc app=leetcode.cn id=160 lang=python
# @lcpr version=30121
#
# [160] 相交链表
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        head1 = ListNode(0, )
        head2 = ListNode(0, )
        head1.next, head2.next = headA, headB
        num1, num2=0,0  # 链表的实际长度，不包含虚拟头节点

        it = head1
        while it.next is not None:
            it=it.next
            num1+=1

        it = head2
        while it.next is not None:
            it=it.next
            num2+=1

        if num2<num1:
            head1, head2=head2, head1
            num1, num2  = num2, num1
        
        it1, it2=head1, head2
        delta_num=num2-num1
        while delta_num>0:
            it2=it2.next
            delta_num-=1
        
        while it1 is not None:
            if it1==it2:
                return it1
            it1, it2= it1.next, it2.next
        return None
        
# @lc code=end



#
# @lcpr case=start
# 8\n[4,1,8,4,5]\n[5,6,1,8,4,5]\n2\n3\n
# @lcpr case=end

# @lcpr case=start
# 2\n[1,9,1,2,4]\n[3,2,4]\n3\n1\n
# @lcpr case=end

# @lcpr case=start
# 0\n[2,6,4]\n[1,5]\n3\n2\n
# @lcpr case=end

#

