#
# @lc app=leetcode.cn id=2105 lang=python
# @lcpr version=30122
#
# [2105] 给植物浇水 II
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution(object):
    def minimumRefill(self, plants, capacityA, capacityB):
        """
        :type plants: List[int]
        :type capacityA: int
        :type capacityB: int
        :rtype: int
        """
        lt, rt =0, len(plants)-1 # 初始化不同
        l_cap, r_cap=capacityA, capacityB
        ans=0
        while lt<=rt:
            if lt == rt:
                if l_cap>=r_cap:
                    if l_cap<plants[lt]:
                        l_cap=capacityA
                        ans+=1
                    l_cap-=plants[lt]
                else:
                    if r_cap<plants[rt]:
                        r_cap=capacityB
                        ans+=1
                    r_cap-=plants[rt]
            else:
                if l_cap<plants[lt]:
                    l_cap=capacityA
                    ans+=1
                l_cap-=plants[lt]
                if r_cap<plants[rt]:
                    r_cap=capacityB
                    ans+=1
                r_cap-=plants[rt]

            if lt==rt or lt+1==rt:  # 两个人都可以给所有植物浇水，因此相遇时必然浇完了全部
                break

            lt, rt=lt+1, rt-1   # 注意两个变量更新的方向不同

        return ans
                
# @lc code=end



#
# @lcpr case=start
# [2,1,1]\n2\n2\n
# @lcpr case=end
# @lcpr case=start
# [1,2,4,4,5]\n6\n5\n
# @lcpr case=end
# @lcpr case=start
# [2,2,3,3]\n5\n5\n
# @lcpr case=end

# @lcpr case=start
# [2,2,3,3]\n3\n4\n
# @lcpr case=end

# @lcpr case=start
# [5]\n10\n8\n
# @lcpr case=end

#

