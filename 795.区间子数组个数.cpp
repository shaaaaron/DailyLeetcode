/*
 * @lc app=leetcode.cn id=795 lang=cpp
 * @lcpr version=30121
 *
 * [795] 区间子数组个数
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
    long long power(int x){ // x>=1
        return (long long)(x)*(x+1)/2;
    }

    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        
        int n=nums.size();
        int i=0,j=0;
        int ans=0;
        while(i<n){
            if(nums[i]<=right){
                j=i;
                while(j<n && nums[j]<=right){
                    j++;
                }j--;// 此时ij是实际的坐标
                // cout<<i<<","<<j<<endl;
                long long tmp=power(j-i+1);
                // cout<<tmp<<endl;
                int len=0;
                for(int k=i;k<=j;k++){
                    if(nums[k]<left){ // 
                        len++;
                    }else{
                        tmp-=power(len);// 
                        len=0;
                    }
                }
                tmp-=power(len);;//
                ans+=tmp;//

                i=j; // 更新i
            }
            i++;
        }
        return ans; // c++报错位置和实际位置不一样
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,4,3]\n2\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,9,2,5,6]\n2\n8\n
// @lcpr case=end

 */

