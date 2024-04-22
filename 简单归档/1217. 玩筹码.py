#
# @lc app=leetcode.cn id=1217 lang=python
# @lcpr version=30122
#
# [1217] 玩筹码
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution(object):
    def minCostToMoveChips(self, position):
        """
        :type position: List[int]
        :rtype: int
        """
        odd, even=0, 0
        for pos in position:
            if pos%2:
                odd+=1
            else:
                even+=1

        return min(odd, even)
# @lc code=end



#
# @lcpr case=start
# [1,2,3]\n
# @lcpr case=end

# @lcpr case=start
# [2,2,2,3,3]\n
# @lcpr case=end

# @lcpr case=start
# [1,1000000000]\n
# @lcpr case=end

#

