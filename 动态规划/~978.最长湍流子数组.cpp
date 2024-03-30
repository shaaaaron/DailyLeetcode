/*
 * @lc app=leetcode.cn id=978 lang=cpp
 * @lcpr version=30121
 *
 * [978] 最长湍流子数组
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
    int maxTurbulenceSize(vector<int>& a) {
        if(a.size()==1 || a.size()==2 && a[0]!=a[1])return a.size();
        if(a.size()==2) return 1;

        // 至少有三个元素
        // 对元素进行特判比较好写，否则没法写
        int tmpAns=0, ans=0;
        for(int i=0;i<a.size();i++){
            if(i==0 || a[i-1]==a[i]){
                tmpAns=1;
            }else if (i==1){
                tmpAns=2;
            }else if (a[i-2]<a[i-1] && a[i-1]>a[i] || a[i-2]>a[i-1] && a[i-1]<a[i]){
                tmpAns++;
            }else{
                tmpAns=2;
            }
            
            ans=max(ans,tmpAns);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [9,4,2,10,7,8,8,1,9]\n
// @lcpr case=end

// @lcpr case=start
// [4,8,12,16]\n
// @lcpr case=end

// @lcpr case=start
// [100]\n
// @lcpr case=end

 */

