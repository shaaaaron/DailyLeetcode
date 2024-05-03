/*
 * @lc app=leetcode.cn id=2115 lang=cpp
 * @lcpr version=30122
 *
 * [2115] 从给定原材料中找到所有可以做出的菜
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
#include <set>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, set<string>> memo;
        unordered_map<string, int> in;
        for(int i=0;i<recipes.size();i++){
            string cur=recipes[i];
            in[cur]+=ingredients[i].size();
            for(string pre:ingredients[i]){
                memo[pre].insert(cur);
            }
        }

        // 提供材料中一定没有要做的菜品
        vector<string> ans;
        deque<string> dq;
        dq.insert(dq.end(), supplies.begin(), supplies.end()); // dq要end
        while(!dq.empty()){
            string cur=dq.front();
            dq.pop_front();
            for(string next:memo[cur]){
                in[next]--;
                if(!in[next]){
                    ans.push_back(next);
                    dq.push_back(next);
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["bread"]\n[["yeast","flour"]]\n["yeast","flour","corn"]\n
// @lcpr case=end

// @lcpr case=start
// ["bread","sandwich"]\n[["yeast","flour"],["bread","meat"]]\n["yeast","flour","meat"]\n
// @lcpr case=end

// @lcpr case=start
// ["bread","sandwich","burger"]\n[["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]]\n["yeast","flour","meat"]\n
// @lcpr case=end

// @lcpr case=start
// ["bread"]\n[["yeast","flour"]]\n["yeast"]\n
// @lcpr case=end

 */

