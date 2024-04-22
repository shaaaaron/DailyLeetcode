#
# @lc app=leetcode.cn id=494 lang=python
# @lcpr version=30120
#
# [494] 目标和
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution(object):
    def findTargetSumWays(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        dict = {0:1}    # 长度至少为1，所以可以这么初始化。如果长度可以为0，这么初始化，如果nums中没有0且target为0，会出错返回1

        for num in nums:
            dict_new = {}
            for key in dict.keys(): # dict.keys()访问所有key
                if dict_new.get(key+num) is  None:      # dict.get()是表达式，不是赋值目标.不存在则返回None
                    dict_new[key+num]=0                 # 如果不在dict中，初始化为0
                dict_new[key+num]+=dict.get(key)        # 如果需要修改和赋值使用下表索引

                if dict_new.get(key-num) is  None:      # 厘清key和value的含义关系
                    dict_new[key-num]=0
                dict_new[key-num]+=dict.get(key)
            dict = dict_new
            # print(dict)   # python中字典的打印非常方版
        return 0 if dict.get(target) is None else dict.get(target)  # 不能使用?:，使用if else
# @lc code=end



#
# @lcpr case=start
# [1,1,1,1,1]\n3\n
# @lcpr case=end

# @lcpr case=start
# [1]\n1\n
# @lcpr case=end

#


if __name__ == "__main__":
    a = [1]
    b = int(input())
    print(Solution().findTargetSumWays(a,b))
