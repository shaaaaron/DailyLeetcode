/*
 * @lc app=leetcode.cn id=1734 lang=cpp
 * @lcpr version=30122
 *
 * [1734] 解码异或后的排列
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
    vector<int> decode(vector<int>& encoded) {
        int n=encoded.size()+1;
        vector<int> ori(n);

        int res=0;
        for(int i=0;i<encoded.size();i++){
            if(i%2==0){
                res^=encoded[i];
            }
        }
        for(int i=1;i<=n;i++){
            res^=i;
        }

        ori[n-1]=res;

        for(int i=n-2;i>=0;i--){
            ori[i]=encoded[i]^ori[i+1];
        }
        return ori;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,1]\n
// @lcpr case=end

// @lcpr case=start
// [6,5,4,6]\n
// @lcpr case=end

 */

