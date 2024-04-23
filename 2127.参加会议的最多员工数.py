#
# @lc app=leetcode.cn id=2127 lang=python
# @lcpr version=30122
#
# [2127] 参加会议的最多员工数
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start

class Solution(object):
    def dfs(self, n):
        if self.visited[n]==True:
            if self.ring[n][0] is None:     # 走到了本次dfs中的一个节点，是一个完整的环
                self.ring[n]=[True, n, 0]   # 更新为入口的节点
                return True, n, 0           # 环，代表节点，当前长度
            else:                           # 链接到了之前的环上
                # self.ring[n]=[True, n, 0] 不能更新
                if self.ring[n][0]==True:   # 插到了环上
                    return False, n, 0                # 链表插入的（环上的）节点
                else:                       # 插到了链条上
                    return False, self.ring[n][1], self.ring[n][2]  # 链表插入的（环上的）节点，不是简单的n
                # 通过链表插入的节点可以找到环

        self.visited[n]=True

        ring_or_link, node, length=self.dfs(self.favorite[n])   # dfs子节点

        if n==node: # 遍历到了环的起点
            self.ring[n]=[ring_or_link, node, length+1]
            idx=self.favorite[n]
            while idx !=n:
                self.ring[idx]=[ring_or_link, node, length+1]
                idx=self.favorite[idx]
            return False, node, 0
        elif ring_or_link ==True:     # 是环
            self.ring[n]=[ring_or_link, node, length+1]
            return ring_or_link, node, length+1
        else:
            self.ring[n]=[ring_or_link, node, length+1]
            return ring_or_link, node, length+1
                
            
    def maximumInvitations(self, favorite):
        """
        :type favorite: List[int]
        :rtype: int
        """
        n=len(favorite)
        self.favorite=favorite
        self.ring=[[None, None, None] for _ in range(n)] 
        # True/Flase表述环/链，对应的环（的代表节点）/链条插到的节点，环/链的长度
        # 注意链条插到的节点不是环的代表节点，而是恰好的插入到的环上的节点，但是可以通过这个节点查询到环
        self.visited=[False for _ in range(n)]
        
        for i in range(n):
            if self.visited[i]==True:
                continue
            self.dfs(i)
        
        ans1, ans2=0, 0 # ans1只放一个大环，ans2放置所有的二环和变体
        dic={}
        for i in range(n):
            if self.ring[i][0]==True and self.ring[i][2]!=2:    # 是环且长度不为2
                ans1=max(ans1, self.ring[i][2])
            elif self.ring[i][0]==False:    # 不是环
                
                insert_node = self.ring[i][1]           # 取出插入节点
                ring_node = self.ring[insert_node][1]   # 取出代表节点

                link_length = self.ring[i][2]
                ring_length = self.ring[ring_node][2]

                if ring_length!=2:          # 是链条，而且链接的环长度为2, 方可继续
                    continue

                if dic.get(ring_node, None) is None:
                    dic[ring_node]=[]

                if len(dic[ring_node])==0:
                    dic[ring_node]=[[insert_node, link_length]] # 二维列表，先节点后大小
                elif len(dic[ring_node])==1:
                    if insert_node==dic[ring_node][0][0]:
                        dic[ring_node][0][1] = max(dic[ring_node][0][1], link_length)
                    else:    
                        dic[ring_node].append([insert_node, link_length])
                else:
                    if insert_node==dic[ring_node][0][0]:
                        dic[ring_node][0][1] = max(dic[ring_node][0][1], link_length)
                    elif insert_node==dic[ring_node][1][0]:
                        dic[ring_node][1][1] = max(dic[ring_node][1][1], link_length)
                    else:
                        tmp=[ [insert_node, link_length], [dic[ring_node][0][0], dic[ring_node][0][1]], [dic[ring_node][1][1], dic[ring_node][1][1]]]
                        sorted_tmp = sorted(tmp, key=lambda x: x[1], reverse=True)    # sorted返回排序的列表
                        # tmp.sort(key=lambda x: x[0])原地进行排序
                        dic[ring_node][0] = [sorted_tmp[0][0], sorted_tmp[0][1]]
                        dic[ring_node][1] = [sorted_tmp[1][0], sorted_tmp[1][1]]

        for i in range(n):
            if self.ring[i][0]==True and self.ring[i][2]==2:    # 所在的是环，大小为2

                ring_node = self.ring[i][1] # 取出代表节点
                if i!=ring_node:    # 每个环只考虑一次
                    continue

                if dic.get(ring_node, None) is not None:
                    tmp=[_[1] for _ in  dic[ring_node]]
                    ans2 += 2+sum(tmp)
                else:
                    ans2 += 2
        return max(ans1, ans2)

# @lc code=end



#
# @lcpr case=start
# [2,2,1,2]\n
# @lcpr case=end

# @lcpr case=start
# [1,2,0]\n
# @lcpr case=end

# @lcpr case=start
# [3,0,1,4,1]\n
# @lcpr case=end

#

if __name__ == "__main__":
    # TODO: Write your Python code here
    s=Solution()
    
    s.maximumInvitations([1,0,3,2,5,6,7,4,9,8,11,10,11,12,10])

    print(s.ring)
