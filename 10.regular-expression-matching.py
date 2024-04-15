#
# @lc app=leetcode.cn id=10 lang=python
# @lcpr version=30122
#
# [10] 正则表达式匹配
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution(object):
    def adjust(self, s):
        i, j=0, 0
        ans=""
        while i<len(s):
            j=i
            starnum, charnum=0, 0
            while j<len(s) and (s[j]==s[i] or s[j]=='*'):
                if s[j]==s[i]:
                    charnum+=1
                else:
                    starnum+=1
                j+=1

            ans+= (charnum-starnum)*str(s[i]) + ("*" if starnum>0 else "")
            i=j # 下一个开始的位置
        return ans

        
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        s = self.adjust(s)

        i,j=0,0  # 当前匹配的字符索引
        while i<len(s) and j<len(p):

            star = False
            if i+1<len(s) and s[i+1]=="*":    # python中双引号和单引号没有区别，都可以用来比较单个字符
                star = True

            
        if i==len(s) and j==len(p):
            return True
        return False
# @lc code=end



#
# @lcpr case=start
# "aa"\n"a"\n
# @lcpr case=end

# @lcpr case=start
# "aa"\n"a*"\n
# @lcpr case=end

# @lcpr case=start
# "ab"\n".*"\n
# @lcpr case=end

#


if __name__ == "__main__":
    # TODO: Write your Python code here
    print(Solution().adjust("a*a*aaaaabbb*bcc"))
