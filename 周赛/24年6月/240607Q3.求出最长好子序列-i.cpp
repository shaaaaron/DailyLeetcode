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

class Solution {
public:
    int maximumLength(vector<int>& nums, int bound) {
        int n=nums.size();
        vector<vector<int>> dp(n+1, vector<int>(30));
        for(int i=0;i<n;i++){
            // 对应dp[i+1][ ]
            for(int j=-1;j<i;j++){ //-1表示从空白开始
                for(int k=0;k<=bound;k++){
                    if(j==-1 || nums[i]==nums[j]){
                        dp[i+1][k]=max(dp[i+1][k], 1+dp[j+1][k]);
                    }else{
                        if(k<bound){
                            dp[i+1][k+1]=max(dp[i+1][k+1], 1+dp[j+1][k]);
                        }
                    }
                }
            }
        }

        int ans=0;

        for(int i=0;i<n;i++){ // 前面的dp使用了相同的
            for(int k=0;k<=bound;k++){
                ans=max(ans, dp[i+1][k]);
            }
        }

        return ans;
    }
};