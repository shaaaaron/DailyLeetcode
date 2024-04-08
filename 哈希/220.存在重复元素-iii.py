#
# @lc app=leetcode.cn id=220 lang=python
# @lcpr version=30121
#
# [220] 存在重复元素 III
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
from collections import deque
class Solution(object):
    def containsNearbyAlmostDuplicate(self, nums, indexDiff, valueDiff):
        """
        :type nums: List[int]
        :type indexDiff: int
        :type valueDiff: int
        :rtype: bool
        """
        i,j =0,0
        memo={}

        # for j in range(len(nums)):
        while j<len(nums):
            if j-i>indexDiff:#
                del memo[ nums[i]//(valueDiff+1)]
                # memo.pop(memo[i%(valueDiff+1)], None)
                i+=1
            
            while j<len(nums) and j-i<=indexDiff:#
                if memo.get( nums[j]//(valueDiff+1)) is not None:
                    return True
                left = memo.get( nums[j]//(valueDiff+1)-1)
                if left is not None and nums[j]-left<=valueDiff:
                    return True
                right = memo.get( nums[j]//(valueDiff+1)+1)
                if right is not None and right-nums[j]<=valueDiff:
                    return True
                
                memo[ nums[j]//(valueDiff+1)]=nums[j]

                j+=1 # 

        return False
# @lc code=end



#
# @lcpr case=start
# [1,2,3,1]\n3\n0\n
# @lcpr case=end

# @lcpr case=start
# [1,5,9,1,5,9]\n2\n3\n
# @lcpr case=end

#

