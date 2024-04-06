#
# @lc app=leetcode.cn id=496 lang=python
# @lcpr version=30121
#
# [496] 下一个更大元素 I
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start

class Solution(object):
    def nextGreaterElement(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        s=[]
        dict={}

        for num in nums2:
            while len(s)!=0 and s[-1]<num:
                dict[s[-1]]=num
                s.pop()
            s.append(num)
            
        return [dict[num] if dict.get(num) is not None else -1 
                    for num in nums1
                    ]
# @lc code=end

# [1,2,3,4]. is not a valid value of type integer[]
# [1,2,3,4]. is not a valid value of type integer[]
# 在部分测试样例上leetcode插件会出错，没有解决方法

#
# @lcpr case=start
# [4,1,2]\n[1,3,4,2].\n
# @lcpr case=end

# @lcpr case=start
# [2,4]\n[1,2,3,4].\n
# @lcpr case=end

#

