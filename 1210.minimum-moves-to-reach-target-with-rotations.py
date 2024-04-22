#
# @lc app=leetcode.cn id=1210 lang=python
# @lcpr version=30122
#
# [1210] 穿过迷宫的最少移动次数
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution(object):
    # def bt(self, i, j, dir):
    #     if i==self.m-1 and j==self.n-2:
    #         if self.ans==-1 or self.now_step<self.ans:
    #             self.ans= self.now_step
    #         return
        
    #     # 可以向右移动
    #     if j+2<self.n and self.grid[i][j+2]==0:
    #         self.now_step+=1
    #         self.vis[i][j+1][dir]=1
    #         self.bt(i, j, dir)
    #         self.vis[i][j+1][dir]=0
    #         self.now_step-=1

    #     if i+2<self.m and self.grid[i+2][j]==0:
    #         self.now_step+=1
    #         self.vis[i+1][j][dir]=1
    #         self.bt(i, j, dir)
    #         self.vis[i+1][j][dir]=0
    #         self.now_step-=1

    #     if dir==0 and i+1<self.m and self.grid[i+1][j]==0 and self.grid[i+1][j+1]==0 and self.vis[i][j][1]==0:
    #         self.now_step+=1
    #         self.vis[i+1][j][0]=1
    #         self.bt(i, j, 1)
    #         self.vis[i+1][j][0]=0
    #         self.now_step-=1

    #     if dir==1 and i+1<self.m and self.grid[i+1][j]==0 and self.grid[i+1][j+1]==0 and self.vis[i][j][1]==1:
    #         self.now_step+=1
    #         self.vis[i][j][1]=1
    #         self.bt(i, j, 0)
    #         self.vis[i][j][1]=0
    #         self.now_step-=1
            
    # def minimumMoves(self, grid):
    #     """
    #     :type grid: List[List[int]]
    #     :rtype: int
    #     """
    #     self.grid=grid
    #     self.m, self.n=len(grid), len(grid[0])
    #     self.vis=[[ [0,0 ] for _ in range(self.n)] for _ in range(self.m)] # (m, n, 2) 0表示向右，1表示向下


    #     self.vis[0][0][1]=1  # 表示蛇的中心位置和方向
    #     self.ans, self.now_step =-1, 0
    #     self.bt(0, 0, 0)
    #     return self.ans
    def check(self, i, j):
        if 0<=i<=self.m-2 and 0<=j<=self.n-2 and self.grid[i][j]==0 and self.grid[i][j+1]==0 and self.grid[i+1][j]==0 and self.grid[i+1][j+1]==0:
            return True
        return False    
    

    def minimumMoves(self, grid):
        self.m, self.n=len(grid), len(grid[0])
        self.grid = grid
        dp=[[ [float('inf'), float('inf')] for _ in range(self.n)] for _ in range(self.m)]
        dp[0][0][0]=0
        if self.check(0, 0):
            dp[0][0][1] = min(dp[0][0][1], dp[0][0][0]+1)

        # 1是向下的，0是向右的
        for i in range(0, self.m):
            for j in range(0, self.n):
                # if i==0 and j==0:
                #     continue

                if self.check(i ,j):    # 尝试旋转
                    dp[i][j][0] = min(dp[i][j][0], dp[i][j][1]+1)
                    dp[i][j][1] = min(dp[i][j][1], dp[i][j][0]+1)

                # 以摊平的方法向右移动
                if self.check(i,j):
                    dp[i][j+1][1] = min(dp[i][j+1][1], dp[i][j][1]+1)

                # 以摊平的方法向下移动
                if self.check(i, j):
                    dp[i+1][j][0] = min(dp[i+1][j][0], dp[i][j][0]+1)

                # 以笔直的方法向右移动
                if j+2<self.n and self.grid[i][j]==0  and self.grid[i][j+1]==0 and self.grid[i][j+2]==0:
                    dp[i][j+1][0] = min(dp[i][j+1][0], dp[i][j][0]+1)
                # 以笔直的方法向下移动
                if i+2<self.n and self.grid[i][j]==0 and self.grid[i+1][j]==0 and self.grid[i+2][j]==0:
                    dp[i+1][j][1] = min(dp[i+1][j][1], dp[i][j][1]+1)

        # print(dp)
        # print((dp[self.m-1][self.n-2][0], dp[self.m-1][self.n-2][1]))

        if dp[self.m-1][self.n-2][0] == float('inf') and  dp[self.m-1][self.n-2][1] == float('inf'):
            return -1 
        else:
            return min(dp[self.m-1][self.n-2][0], dp[self.m-1][self.n-2][1])

# @lc code=end



#

# @lcpr case=start
# [[0,0,1],[0,0,1],[0,0,1]]\n
# @lcpr case=end
# @lcpr case=start
# [[0,0,1],[0,0,1],[0,0,0]]\n
# @lcpr case=end
# @lcpr case=start
# [[0,0,0,0,0,1],[1,1,0,0,1,0],[0,0,0,0,1,1],[0,0,1,0,1,0],[0,1,1,0,0,0],[0,1,1,0,0,0]]\n
# @lcpr case=end

# @lcpr case=start
# [[0,0,1,1,1,1],[0,0,0,0,1,1],[1,1,0,0,0,1],[1,1,1,0,0,1],[1,1,1,0,0,1],[1,1,1,0,0,0]]\n
# @lcpr case=end

#

