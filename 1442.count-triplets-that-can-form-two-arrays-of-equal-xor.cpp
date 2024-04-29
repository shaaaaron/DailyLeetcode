/*
 * @lc app=leetcode.cn id=1442 lang=cpp
 * @lcpr version=30122
 *
 * [1442] 形成两个异或相等数组的三元组数目
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
    int countTriplets(vector<int>& arr) {
        int n=arr.size();
        vector<int> pre_xor(n+1);
        for(int i=0;i<n;i++){
            pre_xor[i+1]=pre_xor[i]^arr[i];
        }

        int ans=0;
        for(int i=0;i+1<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                for(int k=j;k<arr.size();k++){
                    int a=pre_xor[j]^pre_xor[i];
                    int b=pre_xor[k+1]^pre_xor[j];
                    if(a==b) 
                        ans++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,1,6,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,7,9]\n
// @lcpr case=end

// @lcpr case=start
// [7,11,12,9,5,2,7,17,22]\n
// @lcpr case=end

 */

