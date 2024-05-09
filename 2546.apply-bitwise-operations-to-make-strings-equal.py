#
# @lc app=leetcode.cn id=2546 lang=python
# @lcpr version=30122
#
# [2546] 执行逐位运算使字符串相等
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution(object):
    # 对长度为2以上和为1进行分别处理
    # 先总结操作的数字规律
    # 注意到操作必须要对不同的数进行、和位置顺序无关
    # 结合case2思考
    def makeStringsEqual(self, s, target):
        """
        :type s: str
        :type target: str
        :rtype: bool
        """
        # 保证两个字符串长度相同
        if len(s)==1:
            return s==target
        
        s_one=sum(ch=='1' for ch in s)  # 直接计算满足条件的个数
        t_one=sum(ch=='1' for ch in target)
        if s_one>=1 and t_one>=1 or s_one==t_one==0:
            return True
    
        return False
# @lc code=end



#
# @lcpr case=start
# "1010"\n"0110"\n
# @lcpr case=end

# @lcpr case=start
# "11"\n"00"\n
# @lcpr case=end

#

