#
# @lc app=leetcode.cn id=154 lang=python
# @lcpr version=30121
#
# [154] 寻找旋转排序数组中的最小值 II
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans = nums[0]

        l, r=0, len(nums)-1
        while l<=r:
            m=(l+r)//2
            if nums[l]==nums[m]==nums[r]:
                ans=min(ans, nums[m])   # 防止[2,2]中越界
                l+=1
                r-=1
            elif nums[l]<nums[r]:
                return min(ans, nums[l])
            else:
                if nums[m]>=nums[l]:
                    ans=min(ans, nums[l])
                    l=m+1
                else:
                    ans=min(ans, nums[m])
                    r=m-1
        
        return ans
# @lc code=end



#
# @lcpr case=start
# [2,2]\n
# @lcpr case=end

# @lcpr case=start
# [2,2,2,0,1]\n
# @lcpr case=end

#

