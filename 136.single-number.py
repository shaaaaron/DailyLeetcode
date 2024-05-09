#
# @lc app=leetcode.cn id=136 lang=python
# @lcpr version=30122
#
# [136] 只出现一次的数字
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res=0
        for num in nums:
            res^=num
        return res
# @lc code=end



#
# @lcpr case=start
# [2,2,1]\n
# @lcpr case=end

# @lcpr case=start
# [4,1,2,1,2]\n
# @lcpr case=end

# @lcpr case=start
# [1]\n
# @lcpr case=end

#

