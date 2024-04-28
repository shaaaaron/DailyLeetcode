#
# @lc app=leetcode.cn id=1017 lang=python
# @lcpr version=30122
#
# [1017] 负二进制转换
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution(object):
    def baseNeg2(self, n):
        """
        :type n: int
        :rtype: str
        """
        # for i in range(int(0x3ffffffff)):
        i=0
        while i<int(0x3ffffffff): #8f
            oldi=i

            base=1
            sum=0
            while i!=0:
                sum+= (i&1)*base
                base*=-2
                i=i>>1
            if sum==n:
                # print(f"ans: {oldi}")
                # print("ans: {}".format(oldi))

                return bin(oldi)[2:]
            
            # print(i, sum)
            i=oldi+1


# @lc code=end



#
# @lcpr case=start
# 2\n
# @lcpr case=end

# @lcpr case=start
# 3\n
# @lcpr case=end

# @lcpr case=start
# 4\n
# @lcpr case=end

#


if __name__ == "__main__":
    print(Solution().baseNeg2(2)
)