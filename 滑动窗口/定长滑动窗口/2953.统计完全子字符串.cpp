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
    int countSingleSubstring(const string& str, int k){
        int ans=0;
        unordered_map<char,int> memo;
        int unq=0; // 计算恰好出现k次的字符的数量
        for(int i=1;i<=26;i++){ // i是字符的数量，k是每个字符出现的次数
            memo.clear(); // memo甚至支持clear
            unq=0;

            int len=i*k;
            if(len>str.size()) break;
            int lt=0, rt=0;
            while(rt<len){
                memo[str[rt]]++;
                if(memo[str[rt]]==k) unq++;
                rt++;
            }
            if(unq==i) ans++;
            while(rt<str.size()){
                memo[str[rt]]++;
                if(memo[str[rt]]==k) unq++;
                memo[str[lt]]--;
                if(memo[str[lt]]==k-1) unq--;

                if(unq==i) ans++;
                rt++;
                lt++;
            }
        }
        return ans;
    }

    int countCompleteSubstrings(string word, int k) {
        int n=word.size();
        int lt=0, rt=0;
        int ans=0;
        while(rt<n){
            while(rt<n && abs(word[rt]-word[max(lt, rt-1)])<=2){ // 有点tricky
                rt++;
            }
            ans+=countSingleSubstring(word.substr(lt, rt-lt), k); //非常量引用的初始值必须为左值
            lt=rt;
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

