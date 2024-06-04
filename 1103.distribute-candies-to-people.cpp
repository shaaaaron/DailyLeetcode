/*
 * @lc app=leetcode.cn id=1103 lang=cpp
 * @lcpr version=30203
 *
 * [1103] 分糖果 II
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
    vector<int> distributeCandies(int candies, int num_people) {
        long long lt=1, rt=1e9;
        while(lt<=rt){
            long long mid=(lt+rt)/2;
            if(mid*(mid+1)/2>candies){
                rt=mid-1;
            }else{
                lt=mid+1;
            }
        }
        // cout<<rt<<endl;
        // rt就是目前最多的完整分配次数
        vector<int> res(num_people, 0);
        for(int i=0;i<num_people;i++){
            if(rt<i+1) break;
            int last=rt/num_people*num_people+i+1;
            if(last>rt) last-=num_people;
            res[i]=(i+1 + last)*((last-(i+1))/num_people+1)/2;
        }
        res[rt%num_people]+=candies-(rt+1)*rt/2;
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 7\n4\n
// @lcpr case=end

// @lcpr case=start
// 10\n3\n
// @lcpr case=end

 */

