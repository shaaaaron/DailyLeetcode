#
# @lc app=leetcode.cn id=34 lang=python
# @lcpr version=30121
#
# [34] 在排序数组中查找元素的第一个和最后一个位置
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        left, right=0, len(nums)-1
        while left<=right:
            mid=(left+right)//2
            if nums[mid]>=target:
                right=mid-1
            else:
                left=mid+1
        
        if left<0 or left>=len(nums) or nums[left]!=target:
            return (-1,-1)
        
        ans1=left

        left, right=0, len(nums)-1
        while left<=right:
            mid=(left+right)//2
            if nums[mid]<=target:
                left=mid+1
            else:
                right=mid-1
        
        ans2=right

        return (ans1, ans2)
# @lc code=end



#
# @lcpr case=start
# [5,7,7,8,8,10]\n8\n
# @lcpr case=end

# @lcpr case=start
# [5,7,7,8,8,10]\n6\n
# @lcpr case=end

# @lcpr case=start
# []\n0\n
# @lcpr case=end

#

