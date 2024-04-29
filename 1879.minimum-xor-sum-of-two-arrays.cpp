/*
 * @lc app=leetcode.cn id=1879 lang=cpp
 * @lcpr version=30122
 *
 * [1879] 两个数组最小的异或值之和
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
// n<=10全排列，n<=20全组合 否则会超时
    // vector<int> nums1,nums2;
    // int n;

    // vector<int> vis;
    // int cur_res;
    
    // int ans;
    
    // void bt(int k){
    //     if(k==n){
    //         ans=min(ans, cur_res);
    //         return;
    //     }

    //     for(int i=0;i<n;i++){
    //         if(vis[i]) continue;
    //         vis[i]=1;
    //         cur_res+=nums1[i]^nums2[k];
    //         bt(k+1);
    //         cur_res-=nums1[i]^nums2[k];
    //         vis[i]=0;
    //     }
    // }

    // int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
    //     this->nums1=nums1, this->nums2=nums2; // 
    //     n=nums1.size();

    //     vis.resize(n);
    //     cur_res=0;

    //     ans=INT_MAX;

    //     bt(0);
    //     return ans;
    // int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
    // }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2]\n[2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,3]\n[5,3,4]\n
// @lcpr case=end

 */

