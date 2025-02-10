class Solution:
    def validSubstringCount(self, word1: str, word2: str) -> int:
        ans = 0
        lt, rt = 0, -1  # rt指向下一个即将处理的
        cur_memo = {}   # 记录待满足的字符数量
        not_satified_num = 0 # 满足条件的0的数量

        for chr in word2:
            cur_memo[chr] = cur_memo.get(chr, 0) + 1
            if cur_memo[chr] == 1:
                not_satified_num += 1

        while rt < len(word1): # 如果超过表示已经不满足
            if not_satified_num >0 :
                if rt + 1 >= len(word1):
                    break
            
                rt += 1
                cur_memo[word1[rt]] = cur_memo.get(word1[rt], 0) - 1
                if cur_memo[word1[rt]] == 0:
                    not_satified_num -= 1
                if not_satified_num == 0 :  # 从当前lt开始， 以 rt 到 len(word1)-1结尾的都满足条件
                    ans += len(word1) - rt
            else:
                cur_memo[word1[lt]] += 1
                if cur_memo[word1[lt]] == 1:
                    not_satified_num += 1
                if not_satified_num == 0 :  # 从当前lt开始， 以 rt-1 到 len(word1)-1结尾的都满足条件
                    ans += len(word1) - rt 
                lt += 1
                

        return ans