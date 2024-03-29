#
# @lc app=leetcode.cn id=2908 lang=python
# @lcpr version=30121
#
# [2908] 元素和最小的山形三元组 I
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution(object):
    def minimumSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)

        left = [-1] * len(nums)
        right = [-1] * len(nums)

        left[1] = nums[0] # 长度至少为3
        for i in range(2, n-1): # 2,n-2
            left[i] = min(left[i-1], nums[i-1])

        right[n-2] = nums[n-1]
        for i in range(n-3, 0, -1): # n-2到1
            right[i]=min(right[i+1], nums[i+1]) 
        
        ans =-1

        for i in range(1, n-1):
            if left[i]< nums[i] and nums[i]>right[i]:
                if ans == -1 or left[i] + nums[i] +right[i]<ans:
                    ans = left[i] + nums[i] +right[i]

        return ans
# @lc code=end



#
# @lcpr case=start
# [8,6,1,5,3]\n
# @lcpr case=end

# @lcpr case=start
# [5,4,8,7,10,2]\n
# @lcpr case=end

# @lcpr case=start
# [6,5,4,3,4,5]\n
# @lcpr case=end

#

