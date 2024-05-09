#
# @lc app=leetcode.cn id=1761 lang=python
# @lcpr version=30122
#
# [1761] 一个图中连通三元组的最小度数
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution(object):
    def minTrioDegree(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        node_in=[0 for _ in range(n)]
        memo = [set() for _ in range(n)]    # 使用花括号{}会认为是字典
        for u,v in edges:
            node_in[u-1]+=1 # 注意下标是从1开始的
            node_in[v-1]+=1
            memo[u-1].add(v-1)
            memo[v-1].add(u-1)

        ans=float("inf")
        for i in range(n):
            for j in memo[i]:
                for k in memo[i]:
                    if j==k:
                        continue
                    if j not in memo[k]:
                        continue
                    
                    ans= min(ans, node_in[i]+node_in[j]+node_in[k]-6)
        return -1 if ans==float("inf") else ans

# @lc code=end



#
# @lcpr case=start
# 2\n[[1,2]]\n
# @lcpr case=end
# @lcpr case=start
# 6\n[[1,2],[1,3],[3,2],[4,1],[5,2],[3,6]]\n
# @lcpr case=end

# @lcpr case=start
# 7\n[[1,3],[4,1],[4,3],[2,5],[5,6],[6,7],[7,5],[2,6]]\n
# @lcpr case=end

#

