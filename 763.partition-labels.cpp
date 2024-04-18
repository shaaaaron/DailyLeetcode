/*
 * @lc app=leetcode.cn id=763 lang=cpp
 * @lcpr version=30122
 *
 * [763] 划分字母区间
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
// 本题可以贪心，不需要回溯
    vector<int> partitionLabels(string s) {
        int map[30];
        for(int i=0;i<s.size();i++){
            map[s[i]-'a']=i;// 每个数字的最远位置
        }

        vector<int> ans;
        int i=0, maxloc=0;
        int last=-1; //起点的前一个

        while(i<s.size()){
            maxloc=max(maxloc, map[s[i]-'a']);
            if(i==maxloc){ // 达到了有边界更新，而不是恰好超过的时候更新
                            // 和处理字符串的额逻辑一致
                ans.push_back(i-last);
                last=i;
            }
            i++;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "ababcbacadefegdehijhklij"\n
// @lcpr case=end

// @lcpr case=start
// "eccbbbbdec"\n
// @lcpr case=end

 */

