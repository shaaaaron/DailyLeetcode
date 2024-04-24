/*
 * @lc app=leetcode.cn id=526 lang=cpp
 * @lcpr version=30122
 *
 * [526] 优美的排列
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
    int n;
    vector<int> vis;
    
    int ans;
    
    void bt(int k){
        if(k==n+1) ans++;

        for(int i=1;i<=n;i++){
            if(vis[i]==1) continue;

            if(i%k==0 || k%i==0){
                vis[i]=1;
                bt(k+1);
                vis[i]=0;
            }
        }
    }

    int countArrangement(int n) { //看数据范围，搜就完了
        this->n=n;
        vis.resize(n+1);//全0
        
        bt(1);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 11\n
// @lcpr case=end
// @lcpr case=start
// 15\n
// @lcpr case=end
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

