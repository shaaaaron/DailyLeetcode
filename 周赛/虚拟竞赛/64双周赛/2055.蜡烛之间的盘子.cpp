/*
 * @lc app=leetcode.cn id=2055 lang=cpp
 * @lcpr version=30201
 *
 * [2055] 蜡烛之间的盘子
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
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        s="|"+s+"|";
        vector<pair<int,int>> memo;
        int lt=0,rt=1;
        while(rt<s.size()){
            while(rt<s.size() && s[rt]=='*'){
                rt++;
            }
            memo.push_back(make_pair(lt,rt));
            lt=rt; 
            rt++;   // |(lt)*(rt)
        }
        
        vector<int> pre_sum(memo.size()+1);
        for(int i=0;i<memo.size();i++){
            pre_sum[i+1]=pre_sum[i] + memo[i].second-memo[i].first+1-2;
            // cout<<pre_sum[i+1]<<endl;
        }
        
        vector<int> ans;
        for(auto & q:queries){
            int x=q[0]+1,y=q[1]+1;
            int lt=0, rt=memo.size()-1;
            while(lt<=rt){
                int md=(lt+rt)/2;
                if(memo[md].first>=x){ // 也就是右边区间应该满足的条件
                    rt=md-1;
                }else{
                    lt=md+1;
                }
            }
            x=lt;
            
            lt=0, rt=memo.size()-1;
            while(lt<=rt){
                int md=(lt+rt)/2;
                if(memo[md].second<=y){ // 也就是左边区间应该满足的条件
                    lt=md+1;
                }else{
                    rt=md-1;
                }
            }
            y=rt;
            // cout<<x<<y<<endl;
            if(x<=y)
                ans.push_back(pre_sum[y+1]-pre_sum[x]);
            else 
                ans.push_back(0);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "**|**|***|"\n[[2,5],[5,9]]\n
// @lcpr case=end

// @lcpr case=start
// "***|**|*****|**||**|*"\n[[1,17],[4,5],[14,17],[5,11],[15,16]]\n
// @lcpr case=end

 */

