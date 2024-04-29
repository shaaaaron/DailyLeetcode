/*
 * @lc app=leetcode.cn id=2564 lang=cpp
 * @lcpr version=30122
 *
 * [2564] 子字符串异或查询
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
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        unordered_map<int,int> memo;
        int zero_loc=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                if(zero_loc==-1){
                    zero_loc=i;
                }
                continue;
            }
            int cur=0;
            for(int j=i;j<s.size() &&  cur<=(INT_MAX-(s[j]-'0'))/2;j++){
                cur<<=1;
                cur+=s[j]-'0';
                if(memo.find(cur)==memo.end()){
                    memo[cur]=i;
                }
            }
        }

        vector<vector<int>> ans;
        for(auto & vec:queries){
            int q=vec[1]^vec[0];
            if(q==0){
                if(zero_loc==-1){
                    ans.push_back({-1,-1});
                }else{
                    ans.push_back({zero_loc, zero_loc});
                }
            }else{
                if(memo.find(q)==memo.end()){
                    ans.push_back({-1,-1});
                }else{
                    ans.push_back({memo[q],memo[q]+ 32-__builtin_clz(q) -1}); //__builtin_clz计算二进制位数，0导致未定义行为
                }
            } 
            // cout<<q<<endl;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "101101"\n[[0,5],[1,2],[0,0]]\n
// @lcpr case=end
// @lcpr case=start
// "101101"\n[[0,5],[1,2]]\n
// @lcpr case=end

// @lcpr case=start
// "0101"\n[[12,8]]\n
// @lcpr case=end

// @lcpr case=start
// "1"\n[[4,5]]\n
// @lcpr case=end

 */

