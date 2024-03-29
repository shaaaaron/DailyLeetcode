#
# @lc app=leetcode.cn id=576 lang=python
# @lcpr version=30121
#
# [576] 出界的路径数
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
import numpy as np
class Solution(object):
    def findPaths(self, m, n, maxMove, startRow, startColumn):
        """
        :type m: int
        :type n: int
        :type maxMove: int
        :type startRow: int
        :type startColumn: int
        :rtype: int
        """
        if maxMove==0:
            return 0
        
        LARGE_PRIME = 10**9 + 7 # python中没有cnst，通常用大写表示常量
        cnt = 0

        dp = np.full((m,n),0, dtype=int)
        dp[startRow][startColumn] = 1

        for moveNum in range(1, maxMove): #[1, maxmove-1]

            for i in range(m):              # 第一脚就可以踢出界
                cnt= (cnt+dp[i][0]+dp[i][n-1]) % LARGE_PRIME
            for j in range(n):
                cnt= (cnt+dp[0][j]+dp[m-1][j]) % LARGE_PRIME

            dp_new = np.full((m,n),0, dtype=int)
            for i in range(m):      # 从[i][j]可以向四个方向踢球
                for j in range(n):
                    for di,dj in [(-1,0), (1,0), (0,1), (0,-1)]:
                        if 0<=i+di<m and 0<=j+dj<n: # 如果合法
                            # dp_new[i+di][j+dj]+=dp[i][j]
                            dp_new[i+di][j+dj] = (dp_new[i+di][j+dj] + dp[i][j]) % LARGE_PRIME
            # print(dp_new)
            dp = dp_new # 是浅拷贝不是深拷贝
        
        # 最后一次遍历，所有边角计算一次
        for i in range(m):
            cnt= (cnt+dp[i][0]+dp[i][n-1]) % LARGE_PRIME
        for j in range(n):
            cnt= (cnt+dp[0][j]+dp[m-1][j]) % LARGE_PRIME

        return cnt
# @lc code=end



#
# @lcpr case=start
# 2\n2\n2\n0\n0\n
# @lcpr case=end

# @lcpr case=start
# 1\n3\n3\n0\n1\n
# @lcpr case=end

# @lcpr case=start
# 36\n5\n50\n15\n3\n
# @lcpr case=end