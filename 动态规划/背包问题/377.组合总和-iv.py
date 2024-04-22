#
# @lc app=leetcode.cn id=377 lang=python
# @lcpr version=30122
#
# [377] 组合总和 Ⅳ
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution(object):
    def combinationSum4(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        ans=0
        dp=[0 for _ in range(target+1)]
        dp[0]=1
        for i in range(1, target+1):
            for val in nums:
                if i>=val:
                    dp[i]+=dp[i-val]

        return dp[target]
# @lc code=end



#
# @lcpr case=start
# [1,2,3]\n4\n
# @lcpr case=end

# @lcpr case=start
# [9]\n3\n
# @lcpr case=end

#

