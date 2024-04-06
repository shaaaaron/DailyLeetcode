#
# @lc app=leetcode.cn id=739 lang=python
# @lcpr version=30121
#
# [739] 每日温度
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution(object):
    def dailyTemperatures(self, temperatures):
        """
        :type temperatures: List[int]
        :rtype: List[int]
        """
        ans=[0]*len(temperatures)

        s=[]
        for idx, num in enumerate(temperatures):    # 使用单调栈，并且记录是后面几天，因此需要idx
            while len(s)!=0 and temperatures[s[-1]]<num:       # 温度严格大的一天，因此这里严格
                idx2=s[-1]
                ans[idx2]=idx-idx2  # 使用列表直接索引
                s.pop()
            s.append(idx)

        return ans

        
# @lc code=end

#
# @lcpr case=start
# [73,74,75,71,69,72,76,73]\n
# @lcpr case=end

# @lcpr case=start
# [30,40,50,60]\n
# @lcpr case=end

# @lcpr case=start
# [30,60,90]\n
# @lcpr case=end

#

