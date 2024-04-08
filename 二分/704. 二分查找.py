#
# @lc app=leetcode.cn id=704 lang=python
# @lcpr version=30121
#
# [704] 二分查找
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        left, right=0, len(nums)-1

        while left<=right:
            mid=(left+right)//2
            if nums[mid]<=target:   # 如果有重复的，会找到最右边
                                    # 如果等于，left会出去
                left=mid+1
            else:
                right=mid-1
        
        return right if nums[right]==target else -1
# @lc code=end



#
# @lcpr case=start
# [-1,0,3,5,9,12]\n9\n
# @lcpr case=end

# @lcpr case=start
# [-1,0,3,5,9,12]\n2\n
# @lcpr case=end

#


if __name__ == "__main__":
    # TODO: Write your Python code here
    a=[1,2,3,3,3,3,3,4]
    print(Solution().search(a,3))
    pass
