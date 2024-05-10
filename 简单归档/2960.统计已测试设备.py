#
# @lc app=leetcode.cn id=2960 lang=python3
# @lcpr version=30201
#
# [2960] 统计已测试设备
#


# @lcpr-template-start
from typing import List
# @lcpr-template-end
# @lc code=start
class Solution:
    def countTestedDevices(self, batteryPercentages: List[int]) -> int:
        ans, leak=0, 0
        for battery in batteryPercentages:
            if battery>leak:
                ans+=1
                leak+=1
        return ans
# @lc code=end



#
# @lcpr case=start
# [1,1,2,1,3]\n
# @lcpr case=end

# @lcpr case=start
# [0,1,2]\n
# @lcpr case=end

#

