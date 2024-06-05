
# @lc app=leetcode.cn id=3072 lang=cpp
# @lcpr version=30202

# [3072] 将元素分配到两个数组中 II


from sortedcontainers import SortedList
from typing import List
from bisect import bisect_right  # Add this import
# @lcpr-template-start
# @lcpr-template-end
# @lc code=start
class Solution:
    def resultArray(self, nums: List[int]) -> List[int]:
        arr1, arr2=SortedList(), SortedList()
        arr1.add(nums[0])
        arr2.add(nums[1])
        ans1, ans2=[nums[0]], [nums[1]]

        for i in range(2, len(nums)):
            num=nums[i]
            cnt1=len(arr1)-bisect_right(arr1, num)
            cnt2=len(arr2)-bisect_right(arr2, num)
            if cnt1>cnt2 or cnt1==cnt2 and len(arr1)<len(arr2):
                arr1.add(num)
                ans1.append(num)
            elif cnt1<cnt2 or cnt1==cnt2 and len(arr1)>len(arr2):
                arr2.add(num)
                ans2.append(num)
            else:
                arr1.add(num)
                ans1.append(num)

        return ans1+ans2
# @lc code=end




# @lcpr case=start
# [2,1,3,3]\n
# @lcpr case=end

# @lcpr case=start
# [5,14,3,1,2]\n
# @lcpr case=end

# @lcpr case=start
# [3,3,3,3]\n
# @lcpr case=end

