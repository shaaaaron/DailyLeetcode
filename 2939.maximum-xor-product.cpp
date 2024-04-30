/*
 * @lc app=leetcode.cn id=2939 lang=cpp
 * @lcpr version=30122
 *
 * [2939] 最大异或乘积
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
    int maximumXorProduct(long long a, long long b, int n) {
        long long mask=((long long)1<<n)-1;// long long 1
        long long inv_mask=~mask;
        
        long long x=0;
            
        if((inv_mask&a)==(inv_mask&b) ){
            int first=true;
            for(int i=n-1;i>=0;i--){
                long long bit_mask=(long long )1<<i;
                if((a&bit_mask)==0 && (b&bit_mask)==0){
                    x|=bit_mask;
                }else if((a&bit_mask)==0 && (b&bit_mask)!=0){
                    if(first){
                        first=false;
                        x|=bit_mask;
                    }
                }else if((a&bit_mask)!=0 && (b&bit_mask)==0){
                    if(first) first=false;
                    else if(!first){
                        x|=bit_mask;
                    }
                }
            }
        }else{
            // 调整a更大
            if((inv_mask&a)<(inv_mask&b)) swap(a,b);
            for(int i=n-1;i>=0;i--){
                long long bit_mask=(long long )1<<i;
                if((a&bit_mask)==0 && (b&bit_mask)==0){
                    x|=bit_mask;
                }else if((a&bit_mask)!=0 && (b&bit_mask)==0){
                    x|=bit_mask;
                }
            }
        }
        int P=1000*1000*1000+7;
        return (a^x)%P*((b^x)%P)%P;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 12\n5\n4\n
// @lcpr case=end

// @lcpr case=start
// 6\n7\n5\n
// @lcpr case=end

// @lcpr case=start
// 1\n6\n3\n
// @lcpr case=end

 */

