#
# @lc app=leetcode.cn id=503 lang=python
# @lcpr version=30121
#
# [503] 下一个更大元素 II
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution(object):
    def nextGreaterElements(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # 和496的区别在于，496是求指定元素的下一个，使用hash，单调栈存元素（方便）
                    #    503求所有元素的下一个，单调栈存索引
        ans=[-1]*len(nums)
        n=len(nums)
        s=[]
        for i in range(2*n-1):  # 只需要环状遍历
            idx=i%n             # 但是索引可以按实际索引
            while len(s)!=0 and nums[s[-1]]<nums[idx]:
                ans[s[-1]]=nums[idx]
                s.pop()
            s.append(idx)

        return ans
# @lc code=end



#
# @lcpr case=start
# [1,2,1]\n
# @lcpr case=end

# @lcpr case=start
# [1,2,3,4,3]\n
# @lcpr case=end

#

