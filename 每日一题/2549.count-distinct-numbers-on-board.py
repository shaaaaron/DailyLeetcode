#
# @lc app=leetcode.cn id=2549 lang=python
# @lcpr version=30120
#
# [2549] 统计桌面上的不同数字
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution(object):
    def distinctIntegers(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n==1:
            return 1
        else:
            return n-1
# @lc code=end



#
# @lcpr case=start
# 5\n
# @lcpr case=end

# @lcpr case=start
# 3\n
# @lcpr case=end

#


if __name__ == "__main__":
    # TODO: Write your Python code here
    pass
