#
# @lc app=leetcode.cn id=912 lang=python
# @lcpr version=30121
#
# [912] 排序数组
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
from random import *

class Solution(object):
    def quicksort(self, nums, low, high):
        if low < high:
            # Partitioning index
            pi = self.partition(nums, low, high)
            
            # Separately sort elements before and after partition
            left_pi, right_pi=pi, pi
            while left_pi>=low and nums[left_pi]==nums[pi]:
                left_pi-=1
            while right_pi<=high and nums[right_pi]==nums[pi]:
                right_pi+=1

            self.quicksort(nums, low, left_pi)
            self.quicksort(nums, right_pi, high)

    def partition(self, nums, low, high):
        # pivot = nums[high]  # 选择最后一个元素作为主元
        pivot_idx = randint(low, high)
        nums[high], nums[pivot_idx]=nums[pivot_idx], nums[high]
        pivot = nums[high]
        i = low  # 第一个需要变更的元素位置
        
        for j in range(low, high):
            if nums[j] <= pivot:    # 如果发现了需要放在pivot之前的元素
                nums[i], nums[j] = nums[j], nums[i]  # Swap
                i = i + 1
        
        nums[i], nums[high] = nums[high], nums[i]  # 最后的i就是主元的位置
        return i

    def sortArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        self.quicksort(nums, 0, len(nums)-1)
        return nums

# @lc code=end



#
# @lcpr case=start
# [5,2,3,1]\n
# @lcpr case=end

# @lcpr case=start
# [5,1,1,2,0,0]\n
# @lcpr case=end

#

