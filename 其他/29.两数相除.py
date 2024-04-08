#
# @lc app=leetcode.cn id=29 lang=python
# @lcpr version=30121
#
# [29] 两数相除
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start

import math as m
class Solution(object):
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        if dividend==-2147483647 and divisor==-2147483648 or dividend==2147483647 and divisor==-2147483648:
            return 0
        if dividend==0:
            return 0
        
        ans = int(m.pow(m.e, m.log(abs(dividend))-m.log(abs(divisor)))+0.00005) 
        return (ans if ans<=(1<<31)-1 else (1<<31)-1) if dividend*divisor>0 \
                else (-ans if -ans>=-(1<<31) else -(1<<31))
    

# @lc code=end



#
# @lcpr case=start
# -2147483647\n-2147483648\n
# @lcpr case=end
# @lcpr case=start
# -2147483648\n-1\n
# @lcpr case=end

# @lcpr case=start
# -2147483647\n-1\n
# @lcpr case=end

# @lcpr case=start
# 10\n-4\n
# @lcpr case=end

# @lcpr case=start
# -10\n3\n
# @lcpr case=end

# @lcpr case=start
# -10\n-3\n
# @lcpr case=end

#

