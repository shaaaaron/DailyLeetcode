/*
 * @lc app=leetcode.cn id=1759 lang=cpp
 * @lcpr version=30121
 *
 * [1759] 统计同质子字符串的数目
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
    int f(long long x){ // 必须将中间结果暂存为longlong然后转化为int！
        const int PRIME = 1000*1000*1000+7;
        if(x%2==0)return (x/2)%PRIME*((x+1)%PRIME)%PRIME;
        else return (x)%PRIME*((x+1)/2%PRIME)%PRIME;
    }

    int countHomogenous(string s) {
        const int PRIME = 1000*1000*1000+7;

        int n=s.size(), ans=0;
        int left=0;

        if(n==1) return 1;

        for(int i=0;i<n;i++){
            // if(i==n-1){  最后一个也需要看是不是相同
            if(i>0 && s[i]!=s[i-1]){
                int len=i-1-left+1;
                ans=(ans+f(len))%PRIME;
                left=i;
            }
            
            if(i==n-1){ // 没有ifelse，直接放在后面
                int len=i-left+1;
                ans=(ans+f(len))%PRIME;
            } 
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abbcccaa"\n
// @lcpr case=end

// @lcpr case=start
// "xy"\n
// @lcpr case=end

// @lcpr case=start
// "zzzzz"\n
// @lcpr case=end

 */

