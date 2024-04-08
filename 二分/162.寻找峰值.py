#
# @lc app=leetcode.cn id=162 lang=python
# @lcpr version=30121
#
# [162] 寻找峰值
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution(object):
    def checkpeak(self, nums, i):   # 默认至少两个元素
        n=len(nums)
        if i==0 and nums[0]>nums[1] or i==n-1 and nums[n-2]<nums[n-1] or nums[i-1]<nums[i] and nums[i]>nums[i+1]:
            return True
        else:
            return False

    def findPeakElement(self, nums):    # 题目中有两个相邻元素不相等
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums)==1:
            return 0
        n=len(nums)
        l, r=0, n-1
        while l<=r:
            mid=(l+r)//2
            if self.checkpeak(nums, mid):
                return mid
            elif mid!=0 and nums[mid-1]>nums[mid]: # 左边的山峰更高
                r=mid-1
            else:
                l=mid+1
        
# @lc code=end



#
# @lcpr case=start
# [1,2,3,1]\n
# @lcpr case=end

# @lcpr case=start
# [1,2,1,3,5,6,4]\n
# @lcpr case=end

#

