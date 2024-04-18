/*
 * @lc app=leetcode.cn id=738 lang=cpp
 * @lcpr version=30122
 *
 * [738] 单调递增的数字
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
// 二分似乎稳过
// 不二分也可以，下面是思路
// 首先，希望第一个数充分大
// 如果和原来数不等，则后面都9
// 如果相等，我希望第二个数充分大...
// 但是这不一定是对的，我的方法对120只能得到99，但实际上119

// 所以每次找到（最前面的）递减段，第一个数--，后面都999。
// 然后再次检查，直到没有递减段

    int monotoneIncreasingDigits(int n) {
        if(n==0) return 0;

        vector<int>nums;
        while(n){
            nums.push_back(n%10);
            n/=10;
        }
        reverse(nums.begin(), nums.end());
    
        int len=nums.size();
        while(true){
            bool flag=false;
            for(int i=0;i+1<nums.size();i++){
                if(nums[i]>nums[i+1]){
                    flag=true;

                    nums[i]--;
                    for(int j=i+1;j<nums.size();j++){
                        nums[j]=9;
                    }
                }
            }

            if(!flag){
                break;
            }     
        }

        int i=0, ans=0;
        while(i<nums.size()){
            ans*=10;
            ans+=nums[i];
            i++;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 20\n
// @lcpr case=end
// @lcpr case=start
// 10\n
// @lcpr case=end

// @lcpr case=start
// 1234\n
// @lcpr case=end

// @lcpr case=start
// 332\n
// @lcpr case=end

 */

