#
# @lc app=leetcode.cn id=240 lang=python
# @lcpr version=30121
#
# [240] 搜索二维矩阵 II
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution(object):
    def search(self, matrix, lx, ly, hx, hy, tar):
        if lx<=hx and ly<=hy:   #
            # print(lx,ly,hx,hy)
            midx, midy=(lx+hx)//2, (ly+hy)//2
            if matrix[midx][midy]==tar:
                return True
            
            if tar<matrix[midx][midy]:  # 注意，递归可以不重复，并且让递归的条件严格减小
                return self.search(matrix, lx,ly,hx,midy-1, tar) or self.search(matrix, lx,midy,midx-1,hy,tar)
            else:
                return self.search(matrix, midx+1,ly,hx,hy,tar) or self.search(matrix, lx,midy+1,midx,hy,tar)
        
        return False
        
        
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        return self.search(matrix, 0, 0, len(matrix)-1, len(matrix[0])-1, target)
        
# @lc code=end



#
# @lcpr case=start
# [[3,4,5],[8,9,10],[13,14,15]]\n5\n
# @lcpr case=end
# @lcpr case=start
# [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n5\n
# @lcpr case=end

# @lcpr case=start
# [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n20\n
# @lcpr case=end

#

