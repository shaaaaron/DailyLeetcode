#
# @lc app=leetcode.cn id=82 lang=python
# @lcpr version=30121
#
# [82] 删除排序链表中的重复元素 II
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
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        fakehead = ListNode(200, head)
        before = fakehead
        while True:
            if before is None or before.next is None or before.next.next is None:
                return fakehead.next
            curr=before.next
            curr_rt=curr.next

            flag = False
            while curr_rt is not None and curr.val == curr_rt.val:
                curr_rt=curr_rt.next
                flag= True # 发生了冲突
            
            if flag:
                before.next=curr_rt
            else:
                before=before.next

        
# @lc code=end



#
# @lcpr case=start
# [1,2,3,3,4,4,5]\n
# @lcpr case=end

# @lcpr case=start
# [1,1,1,2,3]\n
# @lcpr case=end

#

