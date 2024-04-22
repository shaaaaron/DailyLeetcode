/*
 * @lc app=leetcode.cn id=467 lang=cpp
 * @lcpr version=30121
 *
 * [467] 环绕字符串中唯一的子字符串
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
    char nextChar(char x){
        if(x=='z')return 'a';
        return x+1;
    }

    int findSubstringInWraproundString(string s) {
        int n = s.size();

        int count[26]={0};  // 太天才了
                            
        // 初始化没问题
        char firstChat;
        int strLen;         // 遍历到当前字符，字符串的长度
        for(int i=0;i<n;i++){
            if(i==0 || nextChar(s[i-1])!=s[i]){//新的字符串开始
                firstChat = s[i];
                strLen =1;
            }
            count[s[i]-'a']= max(count[s[i]-'a'], strLen);
            strLen++;
        }

        int ans=0;
        for(int i=0;i<26;i++){
            if(count[i]>0)
                ans+= count[i];
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "a"\n
// @lcpr case=end

// @lcpr case=start
// "cac"\n
// @lcpr case=end

// @lcpr case=start
// "zab"\n
// @lcpr case=end

 */

