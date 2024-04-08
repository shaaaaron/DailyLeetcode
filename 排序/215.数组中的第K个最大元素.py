#
# @lc app=leetcode.cn id=215 lang=python
# @lcpr version=30121
#
# [215] 数组中的第K个最大元素
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
import heapq
class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        heap=[]

        for num in nums:
            heapq.heappush(heap, num)
            if len(heap)>k:
                heapq.heappop(heap)
        # print(heap)

        return heap[0]

# @lc code=end



#
# @lcpr case=start
# 2\n
# @lcpr case=end

# @lcpr case=start
# 4\n
# @lcpr case=end

#

