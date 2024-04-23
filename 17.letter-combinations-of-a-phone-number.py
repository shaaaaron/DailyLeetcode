#
# @lc app=leetcode.cn id=17 lang=python
# @lcpr version=30122
#
# [17] 电话号码的字母组合
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
from collections import deque

# 回溯法，一般可以解决如下几种问题：

# 组合问题：N个数里面按一定规则找出k个数的集合
# 切割问题：一个字符串按一定规则有几种切割方式
# 子集问题：一个N个数的集合里有多少符合条件的子集
# 排列问题：N个数按一定规则全排列，有几种排列方式
# 棋盘问题：N皇后，解数独等等
# void backtracking(参数) {
#     if (终止条件) {
#         存放结果;
#         return;
#     }

#     for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
#         处理节点;
#         backtracking(路径，选择列表); // 递归
#         回溯，撤销处理结果
#     }
# }


# 回溯算法用于寻找所有的可行解，如果发现一个解不可行，则会舍弃不可行的解。在这道题中，由于每个数字对应的每个字母都可能进入字母组合，因此不存在不可行的解，直接穷举所有的解即可。
# 回溯用一个全局状态表示，每次dfs前都更新和还原状态。遍历到终止就添加到ans中。
# 传递参数还是全局状态？后者似乎更简单
# 本题中我的写法相当于bfs
class Solution(object): 
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if digits == "":
            return []
        
        dq = deque([""])    # 不能deque("")而是要用列表初始化
        dic = {
            "2":"abc",
            "3":"def",
            "4":"ghi",
            "5":"jkl",
            "6":"mno",
            "7":"pqrs",
            "8":"tuv",
            "9":"wxyz",
        }

        for number in digits:
            qsize=len(dq)

            for i in range(qsize):
                for ch in dic[number]:
                    dq.append(dq[0]+ch)
                dq.popleft()
        return list(dq)
            


# @lc code=end



#
# @lcpr case=start
# "23"\n
# @lcpr case=end

# @lcpr case=start
# ""\n
# @lcpr case=end

# @lcpr case=start
# "2"\n
# @lcpr case=end

#

