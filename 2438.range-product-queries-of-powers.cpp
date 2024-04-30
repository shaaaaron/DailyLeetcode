/*
 * @lc app=leetcode.cn id=2438 lang=cpp
 * @lcpr version=30122
 *
 * [2438] 二的幂数组中查询范围内的乘积
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
// 一种方法是前后缀优化，不过乘法难以进行，这里直接快速幂
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        while(n){
            powers.push_back(n&(-n)); // 取最后一个
            n&=(n-1);//去除最后一个
        }
        // reverse(powers.begin(), powers.end());
        // for(int num:powers){
        //     cout<<" "<<num;
        // }cout<<endl;
        // unordered_map<int,int> memo;
        // memo[0]=1;
        int PRIME=1000*1000*1000+7;

        // function<int(int)> two_pow = [&](int n){ // 需要等于号
        //     if(memo.find(n)!=memo.end())
        //         return memo[n];
        //     int ans= n%2?2:1;
        //     ans=two_pow(n/2)*two_pow(n/2)%PRIME*ans%PRIME;
        //     return memo[n]=ans;
        // };

        vector<int> ans;
        for(auto q:queries){
            long long cur=1; // 如果要乘并且mod PRIME一定要防止越界！
            for(int i=q[0];i<=q[1];i++){
                cur=(cur*powers[i])%PRIME;
            }
            ans.push_back(cur);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 919\n[[5,5],[4,4],[0,1],[1,5],[4,6],[6,6],[5,6],[0,3],[5,5],[5,6],[1,2],[3,5],[3,6],[5,5],[4,4],[1,1],[2,4],[4,5],[4,4],[5,6],[0,4],[3,3],[0,4],[0,5],[4,4],[5,5],[4,6],[4,5],[0,4],[6,6],[6,6],[6,6],[2,2],[0,5],[1,4],[0,3],[2,4],[5,5],[6,6],[2,2],[2,3],[5,5],[0,6],[3,3],[6,6],[4,4],[0,0],[0,2],[6,6],[6,6],[3,6],[0,4],[6,6],[2,2],[4,6]]\n
// @lcpr case=end
// @lcpr case=start
// 15\n[[0,1],[2,2],[0,3]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[0,0]]\n
// @lcpr case=end

 */

