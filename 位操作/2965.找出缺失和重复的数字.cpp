/*
 * @lc app=leetcode.cn id=2965 lang=cpp
 * @lcpr version=30202
 *
 * [2965] 找出缺失和重复的数字
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
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        for(int i=1;i<=n*n;i++)
            ans^=i;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans^=grid[i][j];
            }
        }

        ans&=-ans;
        int a=0, b=0;
        for(int i=1;i<=n*n;i++){
            if(i&ans)
                a^=i;
            else
                b^=i;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]&ans)
                    a^=grid[i][j];
                else
                    b^=grid[i][j];
            }
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==a)
                    cnt++;
            }
        }
        
        if(cnt==0)
            return {b, a};
        return {a,b};
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,3],[2,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[9,1,7],[8,9,2],[3,4,6]]\n
// @lcpr case=end

 */

