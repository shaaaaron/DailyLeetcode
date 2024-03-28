#
# @lc app=leetcode.cn id=2580 lang=python
# @lcpr version=30120
#
# [2580] 统计将重叠区间合并成组的方案数
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution(object):
    def countWays(self, ranges):
        """
        :type ranges: List[List[int]]
        :rtype: int
        """

        ranges = sorted(ranges, key= lambda x: (x[0], x[1]))  # 默认根据关键字从小到大排序， 先根据第一个关键字再第二个
        
        cnt = 0
        tmpEnd = -1
        for start, end in ranges:
            if tmpEnd == -1 or tmpEnd>=start:   # 从-1开始数初始化
                tmpEnd = max(tmpEnd, end)
            else:
                cnt+=1      
                tmpEnd=end  # 更新全部属性，不能遗漏end
        
        # ranges大小至少为2，因此最后一个区间的集合总是没被统计
        cnt+=1

        # 2^n
        ans = 1
        for i in range(cnt):
            ans=(ans<<1)%(1000000007)   # leetcode的python版本不支持下划线分割整数
        return ans
# @lc code=end



#
# @lcpr case=start
# [[6,10],[5,15]]\n
# @lcpr case=end

# @lcpr case=start
# [[1,3],[10,20],[2,5],[4,8]]\n
# @lcpr case=end

#

