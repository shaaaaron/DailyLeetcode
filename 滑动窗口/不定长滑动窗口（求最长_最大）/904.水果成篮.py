#
# @lc app=leetcode.cn id=904 lang=python
# @lcpr version=30122
#
# [904] 水果成篮
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution(object):
    def totalFruit(self, fruits):
        """
        :type fruits: List[int]
        :rtype: int
        """
        # 至多有两种水果的滑动窗口
        lt, rt, unq=0, 0, 0
        dic={}
        ans=0
        while rt<len(fruits):
            dic.setdefault(fruits[rt], 0)    # 需要有，否则会报错
            dic[fruits[rt]]+=1
            if dic[fruits[rt]]==1:
                unq+=1

            while unq>2:
                dic[fruits[lt]]-=1
                if dic[fruits[lt]]==0:
                    unq-=1
                lt+=1

            ans=max(ans, rt-lt+1)
            rt+=1
        return ans
# @lc code=end



#
# @lcpr case=start
# [1,2,1]\n
# @lcpr case=end

# @lcpr case=start
# [0,1,2,2]\n
# @lcpr case=end

# @lcpr case=start
# [1,2,3,2,2]\n
# @lcpr case=end

# @lcpr case=start
# [3,3,3,1,2,1,1,2,3,3,4]\n
# @lcpr case=end

#

