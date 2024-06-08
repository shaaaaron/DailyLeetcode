class Solution:
    @cache
    def dfs(self, target, i, j):
        # 剩下一个或者更少的元素
        if self.done:
            return 0
        if i >= j:
            self.done = True
            return 0
        nums=self.nums
        ans=0
        if target==nums[i]+nums[i+1]:
            ans=max(ans, 1+self.dfs(target, i+2, j))
        if target==nums[i]+nums[j]:
            ans=max(ans, 1+self.dfs(target, i+1, j-1))
        if target==nums[j-1]+nums[j]:
            ans=max(ans, 1+self.dfs(target, i, j-2))

        return ans

    def maxOperations(self, nums: List[int]) -> int:
        self.nums=nums
        ans, n=0, len(nums)
        # 数组的长度至少为2
        self.done=False
        ans=max(ans, 1+self.dfs(nums[0]  +nums[1]  , 2, n-1))
        ans=max(ans, 1+self.dfs(nums[n-2]+nums[n-1], 0, n-3))
        ans=max(ans, 1+self.dfs(nums[0]  +nums[n-1], 1, n-2))
        return ans
