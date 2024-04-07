#
# @lc app=leetcode.cn id=23 lang=python
# @lcpr version=30121
#
# [23] 合并 K 个升序链表
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
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        head=ListNode()
        before=head

        while True:
            print(before.val)
            tmp=None
            idx=None
            for i, link in enumerate(lists):
                if link is not None and (tmp is None or tmp.val > link.val):
                    tmp=link
                    idx=i
            
            if tmp is None:
                return head.next
            
            before.next=tmp # 变量名不能错写成tmp
            lists[idx]=tmp.next

            before=before.next
            before.next=None # 防止越界



        
# @lc code=end



#
# @lcpr case=start
# [[1,4,5],[1,3,4],[2,6]]\n
# @lcpr case=end

# @lcpr case=start
# []\n
# @lcpr case=end

# @lcpr case=start
# [[]]\n
# @lcpr case=end

#

