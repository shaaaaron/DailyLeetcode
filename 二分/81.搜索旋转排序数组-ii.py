#
# @lc app=leetcode.cn id=81 lang=python
# @lcpr version=30121
#
# [81] 搜索旋转排序数组 II
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: bool
        """
        left, right=0, len(nums)-1
        while left<=right:
            # print(left,right)
            # print(nums[left:right+1])
            mid=(left+right)//2
            if nums[mid]==target:
                return True
            if nums[left]<nums[right]:  # 搜索到了一边
                if nums[mid]<target:
                    left=mid+1
                else:
                    right=mid-1
            elif nums[left]>nums[right]:
                if (nums[mid]>=nums[left] and nums[left]<=target<=nums[mid]) \
                    or (nums[mid]<=nums[right] and (target>nums[right] or target<nums[mid])):
                    right=mid-1
                else:
                    left=mid+1
            elif nums[left]==nums[right]:
                if nums[mid]>nums[left]:
                    if nums[left]<=target<=nums[mid]:
                        right=mid-1
                    else:
                        left=mid+1
                elif nums[mid]<nums[right]:
                    if nums[mid]<=target<=nums[right]:
                        left=mid+1
                    else:
                        right=mid-1
                else:
                    left,right=left+1,right-1
        return False
# @lc code=end



#
# @lcpr case=start
# [2,5,6,0,0,1,2]\n0\n
# @lcpr case=end

# @lcpr case=start
# [2,5,6,0,0,1,2]\n3\n
# @lcpr case=end

#


if __name__ == "__main__":
    # TODO: Write your Python code here
    print(Solution().search([3,1,2,2,2],1))
    pass
