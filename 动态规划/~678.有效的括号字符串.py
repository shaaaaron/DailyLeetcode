#
# @lc app=leetcode.cn id=678 lang=python
# @lcpr version=30121
#
# [678] 有效的括号字符串
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start

# 一个有问题的代码
# bool checkValidString(string s) {
#     int left=0,star=0,right=0;
#     int n =s.size();
#     for(int i=0;i<n;i++){
#         if(s[i]=='(')left++;
#         else if(s[i]=='*')star++;
#         else right++;

#         if(right>left){
#             if(star>=right-left){
#                 star-=(right-left);
#                 left+=(right-left);
#             }else{
#                 return false;
#             }
#         }
#     }
#     cout<<left<<" "<<star<<" "<<right<<endl;
#     if(star>=left-right)return true;
#     return false;
# }

class Solution(object):
    def checkValidString(self, s):
        """
        :type s: str
        :rtype: bool
        """

        leftMin, leftMax = 0, 0  # 左括号的上界和下界，正数表示左括号的数量，负数表示右括号的数量
        n = len(s)
        for i in range(n):
            # print(s[:i+1], leftMin, leftMax)
            if s[i] == '(':
                leftMin += 1
                leftMax += 1
            elif s[i] == '*':
                leftMax += 1
                leftMin = max(leftMin - 1, 0)  # 确保 leftMin 不会小于 0
                # leftMin =  leftMin>0 ? leftMin-1  :0;
                # c++和python三目运算符写法有区别，需要加以区分
            else:
                leftMin -= 1
                leftMax -= 1
                if leftMax < 0:  # 如果 leftMax 变成负数，则表明右括号太多，无法匹配
                    return False
                leftMin = max(leftMin, 0)  # 确保 leftMin 不会小于 0
        return leftMin == 0  # 如果 leftMin 为 0，表示所有左括号都能找到匹配的右括号
# @lc code=end



#
# @lcpr case=start
# "(((((*(*********((*(((((****"\n
# @lcpr case=end

# @lcpr case=start
# "()"\n
# @lcpr case=end

# @lcpr case=start
# "(*)"\n
# @lcpr case=end

# @lcpr case=start
# "(*))"\n
# @lcpr case=end

#

