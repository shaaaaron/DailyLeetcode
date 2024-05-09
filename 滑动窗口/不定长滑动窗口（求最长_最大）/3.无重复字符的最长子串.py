#
# @lc app=leetcode.cn id=3 lang=python
# @lcpr version=30122
#
# [3] 无重复字符的最长子串
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        dic={}
        lt, rt=0, 0
        ans =0 
        while rt<len(s):
            dic.setdefault(s[rt], 0)    # 如果已经有了则不影响
            dic[s[rt]]+=1
            while dic[s[rt]]>1:
                dic[s[lt]]-=1
                lt+=1
            ans=max(ans, rt-lt+1)
            rt+=1
        return ans
# @lc code=end



#
# @lcpr case=start
# "abcabcbb"\n
# @lcpr case=end

# @lcpr case=start
# "bbbbb"\n
# @lcpr case=end

# @lcpr case=start
# "pwwkew"\n
# @lcpr case=end

#

