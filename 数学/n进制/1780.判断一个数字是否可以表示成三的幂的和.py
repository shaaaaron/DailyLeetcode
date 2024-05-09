#
# @lc app=leetcode.cn id=1780 lang=python
# @lcpr version=30122
#
# [1780] 判断一个数字是否可以表示成三的幂的和
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution(object):
    def checkPowersOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        while n:
            if n%3==2:
                return False
            n=n//3
        return True
# @lc code=end



#
# @lcpr case=start
# 12\n
# @lcpr case=end

# @lcpr case=start
# 91\n
# @lcpr case=end

# @lcpr case=start
# 21\n
# @lcpr case=end

#

