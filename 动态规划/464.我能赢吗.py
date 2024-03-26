#
# @lc app=leetcode.cn id=464 lang=python
# @lcpr version=30120
#
# [464] 我能赢吗
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
visited = [-1 for _ in range(1<<20)]
# -1表示没有，1表示true，0表示false

class Solution(object):
    def dfs(self, maxChoosableInteger, desiredTotal, state, nowScore):
        # 递归的状态只和state有关，nowscore可以由state计算，只是因为方便所以在dfs传递
        # dfs先查看visited数组。算出结果是更新visited数组

        if visited[state]!=-1:
            return visited[state]==1 # 不能不要==1，否则返回的就是1(int)而不是true(bool)
        for i in range(1,maxChoosableInteger+1):
            if 1<<(i-1) & state:    # 位操作方法和c++相同
                # 已经被选择，跳过
                continue
            elif i+nowScore>=desiredTotal:
                visited[state]=1
                return True
            else:
                if self.dfs(maxChoosableInteger, desiredTotal, state|1<<(i-1), nowScore+i)==False:
                # 为什么显示dfs未定义。python中需要使用self.，并且在参数中声明self
                    visited[state]=1
                    return True
        visited[state]=0
        return False

    # 首先应该想到，本题是一道搜索题
    def canIWin(self, maxChoosableInteger, desiredTotal):
        """
        :type maxChoosableInteger: int
        :type desiredTotal: int
        :rtype: bool
        """
        if (1+maxChoosableInteger)*maxChoosableInteger/2 <desiredTotal:
            return False
            # 虽然后手的人会输，但是先手的也没法赢
        
        # 力口的判题策略是相同类生命一次，但是方法调用多次。因此使用全局变量需要重新初始化
        # 全局变量在函数中使用需要global，否则相当于重新定义变量
        global visited
        visited = [-1 for _ in range(1<<20)]
        return self.dfs(maxChoosableInteger, desiredTotal, 0, 0)
        # 直接写会有部分测试样例超时，需要进行记忆化搜索 
# @lc code=end



#
# @lcpr case=start
# 10\n11\n
# @lcpr case=end

# @lcpr case=start
# 10\n0\n
# @lcpr case=end

# @lcpr case=start
# 10\n1\n
# @lcpr case=end

#

if __name__ == "__main__":
    # TODO: Write your Python code here
    print(Solution().canIWin(5, 50))
