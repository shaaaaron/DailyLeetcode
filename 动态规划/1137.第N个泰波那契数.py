#
# @lc app=leetcode.cn id=1137 lang=python
# @lcpr version=30121
#
# [1137] 第 N 个泰波那契数
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution(object):
    def find_nth_num(self, n):
        if self.nums[n]!=-1:
            return   self.nums[n]
        else:
            self.nums[n] = self.find_nth_num(n-1)+self.find_nth_num(n-2)+self.find_nth_num(n-3)
            return  self.nums[n]
        
    def tribonacci(self, n):
        """
        :type n: int
        :rtype: int
        """
        self.nums = [-1]*40
        self.nums[0], self.nums[1], self.nums[2] = 0,1,1
        return self.find_nth_num(n)



# @lc code=end



#
# @lcpr case=start
# 4\n
# @lcpr case=end

# @lcpr case=start
# 25\n
# @lcpr case=end

#

