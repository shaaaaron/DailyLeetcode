#
# @lc app=leetcode.cn id=375 lang=python
# @lcpr version=30120
#
# [375] 猜数字大小 II
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
import numpy as np

class Solution(object):
    def getMoneyAmount(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = np.full((n+5,n+5),0,dtype=int) # 必须开大防治dp[j+1][j]越界

        for interval_len in range(1,n+1):   # 区间的实际长度
            for i in range(1,n+2-interval_len):  # 起始坐标，(i, i+len)
                if interval_len==1:
                        dp[i][i+interval_len-1]=0
                else:
                    min_cost = -1
                    for j in range(i, i+interval_len):
                        if min_cost==-1 or j+max(dp[i][j-1], dp[j+1][i+interval_len-1])<min_cost:
                            min_cost=j+max(dp[i][j-1], dp[j+1][i+interval_len-1]) # 反超默认为0
                    dp[i][i+interval_len-1] = min_cost
                # print(f"[{i}, {i+interval_len-1}]:{dp[i][i+interval_len-1]}")
        return dp[1][n]

# @lc code=end

#
# @lcpr case=start
# 10\n
# @lcpr case=end

# @lcpr case=start
# 1\n
# @lcpr case=end

# @lcpr case=start
# 2\n
# @lcpr case=end

#


if __name__ == "__main__":
    # TODO: Write your Python code here
    print(Solution().getMoneyAmount(2))
