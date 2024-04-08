#
# @lc app=leetcode.cn id=4 lang=python
# @lcpr version=30121
#
# [4] 寻找两个正序数组的中位数
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution(object):
    def find(self, k, nums1, nums2, l1, l2):# self
        if l1>=len(nums1):   # 两种递归种植条件，等于号
            return nums2[l2+ k-1]
        elif l2>=len(nums2):
            return nums1[l1+ k-1]
        elif k==1:
            return nums1[l1] if nums1[l1]<=nums2[l2] else nums2[l2]
        else:
            k_tmp = min([k//2, len(nums1)-l1, len(nums2)-l2])    # 当前要查找的，并且保证不越界
            if nums1[l1+k_tmp-1]<=nums2[l2+k_tmp-1]:    # 等于. -1
                l1+=k_tmp
            elif nums1[l1+k_tmp-1]>nums2[l2+k_tmp-1]:
                l2+=k_tmp
            k-=k_tmp
            return self.find(k, nums1, nums2, l1, l2)# self

    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        # 
        n1, n2=len(nums1), len(nums2)
        if (n1+n2)%2==1:
            return self.find( (n1+n2+1)//2, nums1, nums2, 0, 0)
        else:
            return (self.find( (n1+n2)//2, nums1, nums2, 0, 0)+self.find( (n1+n2)//2+1, nums1, nums2, 0, 0) )/2.    ## 在本地/2是浮点数除法，在leetcode上是整数除法，可能是因为return的是整数除法的结果，由于python版本产生了不同的结果。建议整数除法//2,浮点数除法/2.(有小数点)

# @lc code=end



#
# @lcpr case=start
# [1,3]\n[2]\n
# @lcpr case=end

# @lcpr case=start
# [1,2]\n[3,4]\n
# @lcpr case=end

#


if __name__ == "__main__":
    print(Solution().findMedianSortedArrays([1,2], [3,4]))
    a,b=2//2,4//2
    print((a+b)/2)
    pass
