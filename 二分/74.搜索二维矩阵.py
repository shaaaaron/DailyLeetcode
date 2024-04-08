#
# @lc app=leetcode.cn id=74 lang=python
# @lcpr version=30121
#
# [74] 搜索二维矩阵
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        m, n=len(matrix), len(matrix[0])
        l, r=0, m*n-1

        while l<=r:
            mid=(l+r)//2
            if matrix[mid/n][mid%n]==target:    # 模每行元素的个数
                return True
            elif matrix[mid/n][mid%n]<target:
                l=mid+1 # 不能混淆m和mid
            else:
                r=mid-1
        
        return False
# @lc code=end



#
# @lcpr case=start
# [[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n10\n
# @lcpr case=end

# @lcpr case=start
# [[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n20\n
# @lcpr case=end

#

