#
# @lc app=leetcode.cn id=77 lang=python
# @lcpr version=30122
#
# [77] 组合
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start

# 可能的解决方式：dp、回溯。dfs、bfs每次做题之前都想一边
import copy
class Solution(object):
    def bt(self, idx):  # 当前要处理的坐标
        if len(self.now)==self.k:
            self.ans.append(copy.deepcopy(self.now))    # 回溯需要deepcopy
            return 
        if idx>self.n:  # 其实本题不会出现这个情况
            return 

        if len(self.now)+self.n-idx+1 < self.k: # 开始可以不写，运行成功后再减
            return 
        
        for i in range(idx, self.n+1):
            self.now.append(i)
            self.bt(i+1)
            self.now.pop()
        # 可以按依次放的数字进行枚举，也可以按每个数字放不放进行枚举
         


    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        self.ans=[]
        self.now=[]
        self.n=n
        self.k=k    # int也可以作为参数传递

        self.bt(1)  # k及之后的数字都是尚未使用的
        return self.ans
# @lc code=end



#
# @lcpr case=start
# 4\n2\n
# @lcpr case=end

# @lcpr case=start
# 1\n1\n
# @lcpr case=end

#

