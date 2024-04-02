#
# @lc app=leetcode.cn id=42 lang=python
# @lcpr version=30121
#
# [42] 接雨水
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        n=len(height)
        ans=0
        # 使用栈底元素，因为是列表可以直接访问
        s=[]    # 使用idx

        for idx in range(n):
            while len(s)!=0 and height[s[-1]]<height[idx]:
                if len(s)>=2:
                    ans+=(s[-1]-s[-2])*(min(height[idx], height[s[0]]) - height[s[-1]])
                s.pop()
            s.append(idx)

        return ans
# @lc code=end



#
# @lcpr case=start
# [0,1,0,2,1,0,1,3,2,1,2,1]\n
# @lcpr case=end

# @lcpr case=start
# [4,2,0,3,2,5]\n
# @lcpr case=end
# @lcpr case=start
# [4]\n
# @lcpr case=end
# @lcpr case=start
# [4,2]\n
# @lcpr case=end
#

