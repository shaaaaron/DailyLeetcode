/*
 * @lc app=leetcode.cn id=2953 lang=cpp
 * @lcpr version=30122
 *
 * [2953] 统计完全子字符串
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
    int countCompleteSubstrings(string word, int k) {
        int lt=0, rt=0;
        int ans=0,  not_sat_cnt=0; // 完全字符串的数目，不满足条件的相邻字符的数目
        while(rt<k){
            if(rt>=1 && abs(word[rt]-word[rt-1])>2)
                not_sat_cnt++;
            rt++;
        }
        if(not_sat_cnt==0)  // 进行ans判断一次
            ans++;
        cout<<not_sat_cnt<<endl;
        while(rt<word.size()){
            if(abs(word[rt]-word[rt-1])>2)
                not_sat_cnt++;
            if(abs(word[lt]-word[lt+1])>2)
                not_sat_cnt--;

            if(not_sat_cnt==0)
                ans++;
            cout<<not_sat_cnt<<endl;
            lt++;
            rt++;
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "igigee"\n1\n
// @lcpr case=end
// @lcpr case=start
// "igigee"\n6\n
// @lcpr case=end
// @lcpr case=start
// "igigee"\n2\n
// @lcpr case=end

// @lcpr case=start
// "aaabbbccc"\n3\n
// @lcpr case=end
// @lcpr case=start
// "aaabbbccc"\n1\n
// @lcpr case=end

 */

