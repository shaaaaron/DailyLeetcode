#
# @lc app=leetcode.cn id=275 lang=python
# @lcpr version=30121
#
# [275] H 指数 II
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        ans=0
        left, right=1, len(citations)  # 二分h而不是数组
        while left<=right:
            mid=(left+right)//2 # 整除
            if citations[-mid]>=mid:
                left=mid+1
            else:
                right=mid-1
            
        return right
        # 循环结束后right=left-1，根据ifelse可以判断right是满足条件的
        # 例如如果全部都是0，会返回0
# @lc code=end



#
# @lcpr case=start
# [0,1,3,5,6]\n
# @lcpr case=end

# @lcpr case=start
# [1,2,100]\n
# @lcpr case=end

#

