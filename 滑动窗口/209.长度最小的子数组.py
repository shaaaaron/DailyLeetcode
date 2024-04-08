#
# @lc app=leetcode.cn id=209 lang=python
# @lcpr version=30121
#
# [209] 长度最小的子数组
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution(object):
    def minSubArrayLen(self, target, nums):
        """
        :type target: int
        :type nums: List[int]
        :rtype: int
        """
        ans=len(nums)+5
        l, r=0, 0   # l 和r都初始化为0，分别表示当前滑动窗口的最开始的元素和下一个元素（这个实现是没有问题）
        sum=0
        n=len(nums)
        while True:
            while r<n and sum<target:   # 尽可能的相加
                sum+=nums[r]
                r+=1
            if sum<target:              # 如果访问到了数组的最后还没慢，则return
                return ans if ans!=len(nums)+5 else 0
            
            while sum>=target:          # 否则移动l指针，每次移动过程中更新ans
                                        # 这是为了避免tar=8, [1(l),1,1,1,7(r)]时长度为5，但是实际只需要[1,1,1,1(l),7(r)]长度为2的情况
                                        # 这里r的位置只是为了直观显示，实际上在while循环后应该在7的后一个
                ans=min(ans, r-l)
                sum-=nums[l]
                l+=1


# @lc code=end



#

# @lcpr case=start
# 4\n[1,1,1]\n
# @lcpr case=end
# @lcpr case=start
# 7\n[2,3,1,2,4,3]\n
# @lcpr case=end

# @lcpr case=start
# 4\n[1,4,4]\n
# @lcpr case=end

# @lcpr case=start
# 11\n[1,1,1,1,1,1,1,1]\n
# @lcpr case=end

#

