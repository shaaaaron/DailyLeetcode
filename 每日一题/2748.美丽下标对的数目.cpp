/*
 * @lc app=leetcode.cn id=2748 lang=cpp
 * @lcpr version=30203
 *
 * [2748] 美丽下标对的数目
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
    int get_first_digit(int num){
        int ans=0;
        while(num){
            ans=num%10;
            num/=10;
        }
        return ans;
    }

    int countBeautifulPairs(vector<int>& nums) {
        vector<vector<int>> memo(10, vector<int>{}); // 记录和数字互质的那些数字。由于num至少为1，首位一定不为0，所以不记录零。
        vector<int> cnt(10);    // 记录某种末尾数字的数字个数
        for(int i=1;i<=9;i++){  // 首位数字
            for(int j=0;j<=9;j++){
                if(__gcd(i, j)==1){ // 什么鬼？还有这个函数，使用copilot的好处就是能告诉你一些巧妙的内置函数
                    memo[i].push_back(j);
                }
            }
        }
        
        int ans=0;
        for(int i=nums.size()-1;i>=0;i--){
            int first=get_first_digit(nums[i]);
            for(int tmp:memo[first]){
                ans+=cnt[tmp];
            }
            cnt[nums[i]%10]++;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,5,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [11,21,12]\n
// @lcpr case=end

 */

