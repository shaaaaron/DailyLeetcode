/*
 * @lc app=leetcode.cn id=1456 lang=cpp
 * @lcpr version=30122
 *
 * [1456] 定长子串中元音的最大数目
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
    int check(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
            return 1;
        return 0;
    }

    int maxVowels(string s, int k) {
        int left=0,right=0;
        int ans=0, sum=0;
        while(right<k){
            sum+=check(s[right]);
            right++;
        }
        ans=sum;//进行初始化

        while(right<s.size()){
            sum+=check(s[right]);
            sum-=check(s[left]);

            ans=max(ans, sum);
            left++;
            right++;
        }

        return ans;
    }
};
// @lc code=end


/*
// @lcpr case=start
// "ibpbhixfiouhdljnjfflpapptrxgcomvnb"\n33\n
// @lcpr case=end
// @lcpr case=start
// "abciiidef"\n3\n
// @lcpr case=end

// @lcpr case=start
// "aeiou"\n2\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n3\n
// @lcpr case=end

// @lcpr case=start
// "rhythms"\n4\n
// @lcpr case=end

// @lcpr case=start
// "tryhard"\n4\n
// @lcpr case=end

 */

