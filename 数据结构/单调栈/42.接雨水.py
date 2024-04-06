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
    # 63214,则4进来之后将321弹出 => 64，如果有5进来把4弹出。所以使用ind，计算s[-1]-s[-2]表示填平的距离
    # s[0]是当前元素左边所有元素中最大的。其左边或者右边不可能有更大的。从底到顶（本题中从左到右）形如5321递减
    # 所以填平时，最大高度是min(height[idx], height[s[0]])
    # 上面是栈中有两个以上元素；如果只有一个元素，显然为0，接不住雨水，如46
    # 每遍历到一个元素就处理完当前的情况，结尾不需要特殊处理。因为栈底是左边的最大元素，符合接雨水的特性
    # 只需要严格大小才pop元素，因为元素重复不影响雨水计算
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

