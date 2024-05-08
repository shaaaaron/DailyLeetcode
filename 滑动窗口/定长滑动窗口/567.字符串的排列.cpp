/*
 * @lc app=leetcode.cn id=567 lang=cpp
 * @lcpr version=30122
 *
 * [567] 字符串的排列
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;//

        vector<int> memo(26);
        int k=s1.size(), n=s2.size();
        int lt=0, rt=0;
        int neg_cnt=0;// 小于0的数的数量

        while(rt<k){
            memo[s1[rt]-'a']--;
            memo[s2[rt]-'a']++;
            rt++;
        }
        for(int num:memo){
            if(num<0) neg_cnt++;
        }
        if(neg_cnt==0)
            return true;
            
        while(rt<n){
            memo[s2[rt]-'a']++;
            if(memo[s2[rt]-'a']==0) // 在转化的时候记录
                neg_cnt--;
            memo[s2[lt]-'a']--;
            if(memo[s2[lt]-'a']==-1) // 不能是<-1
                neg_cnt++;
            lt++;
            rt++;

            if(neg_cnt==0)
                return true;
        }

        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "eidbaooo"\n
// @lcpr case=end

// @lcpr case=start
// "eidboaoo"\n
// @lcpr case=end

 */

