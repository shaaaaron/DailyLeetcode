#
# @lc app=leetcode.cn id=39 lang=python
# @lcpr version=30121
#
# [39] 组合总和
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution(object):
    # def combinationSum(self, candidates, target):
    #     """
    #     :type candidates: List[int]
    #     :type target: int
    #     :rtype: List[List[int]]
    #     """
    #     candidates=sorted(candidates) # 是否需要

    #     dp=[[] for _ in range(target+1)]
    #     # dp[0]=[] #默认为1
    #     for can in candidates:
    #         if can<= target:
    #             dp[can] = [[can]]   # 注意下标

    #     # print(dp) 这是python有用的地方
    #     for i in range(1, target+1):
    #         for can in candidates:
    #             if i-can<0:
    #                 continue
                
    #             for tmplist in dp[i-can]:
    #                 dp[i].append(tmplist+[can])
        
    #     dp[target] = [sorted(_) for _ in dp[target]]

    #     return list(set(tuple(sublist) for sublist in dp[target])) #list是不可hash的，如果set去重需要转化为tuple
    #     # return list(set(dp[target]))
    
    def combinationSum(self, candidates, target):
        dp=[[] for _ in range(target+1)] # [1, tar]

        # 是不是完全背包？区别在什么地方？ 区别在于前者求的是最大值，现在的求的方法数，确实有席位区别，需要体会一下
        # 先遍历不同数字，再遍历不同目标
        # 先遍历物品，再遍历目标
        for can in candidates:

            for j in range(1, target+1):
                if j-can<0:
                    continue

                if j== can:
                    dp[j].append([can])
                else:
                    for tmplist in dp[j-can]:
                        dp[j].append(tmplist+[can])

        return dp[target]
# @lc code=end

# 一般的背包问题
    # 在这个问题的动态规划解法中，f[i] 表示容量为 i 的背包能够装入物品的最大价值


#
# @lcpr case=start
# [2,3,6,7]\n3\n
# @lcpr case=end

# @lcpr case=start
# [2,3,5]\n8\n
# @lcpr case=end

# @lcpr case=start
# [2]\n1\n
# @lcpr case=end

#

