#
# @lc app=leetcode.cn id=1465 lang=python
# @lcpr version=30121
#
# [1465] 切割后面积最大的蛋糕
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution(object):
    def maxArea(self, h, w, horizontalCuts, verticalCuts):
        """
        :type h: int
        :type w: int
        :type horizontalCuts: List[int]
        :type verticalCuts: List[int]
        :rtype: int
        """
        horizontalCuts=sorted(horizontalCuts)
        verticalCuts=sorted(verticalCuts)
        # 判断数组是否无序，如果无序需要排序

        lastHindx=0
        maxH=-1
        for hInx in horizontalCuts:
            maxH=max(maxH, hInx-lastHindx)
            # 也可以直接使用a[i]-a[i-1]计算当前大小
            lastHindx=hInx
        maxH=max(maxH, h-lastHindx) # 最后一个在循环结束之后计算一次
        # 和2810有点像，主要是最后的特殊处理

        lastWindx=0
        maxW=-1
        for wInx in verticalCuts:
            maxW=max(maxW,wInx-lastWindx)
            lastWindx=wInx
        maxW=max(maxW, w-lastWindx)

        return maxH*maxW%1000000007
        # PRIME=10**9+7

# @lc code=end



#
# @lcpr case=start
# 5\n4\n[1,2,4]\n[1,3]\n
# @lcpr case=end

# @lcpr case=start
# 5\n4\n[3,1]\n[1]\n
# @lcpr case=end

# @lcpr case=start
# 5\n4\n[3]\n[3]\n
# @lcpr case=end

#

