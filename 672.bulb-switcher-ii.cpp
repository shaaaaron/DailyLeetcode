/*
 * @lc app=leetcode.cn id=672 lang=cpp
 * @lcpr version=30122
 *
 * [672] 灯泡开关 Ⅱ
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
    void operate(vector<int> & light, vector<int> idxs, int n){
        for(auto idx: idxs){
            if(idx<n){
                light[idx]=1-light[idx];
            }
        }
    }

    int flipLights(int n, int presses) {
        if(n>=6) n=6;

        vector<int> light(6);
        vector<int> memo(100);

        for(int i=0;i<16;i++){
            int cur_step=__builtin_popcount(i);
            if(cur_step%2!=presses%2 || cur_step>presses) continue;

            int state=i;
            light=vector<int>(6,0);
            for(int j=0;j<4;j++){
                if(state%2){
                    if(j==0){
                        operate(light, vector<int>{0,1,2,3,4,5}, n);
                    }else if(j==1){
                        operate(light, vector<int>{0,2,4}, n);
                    }else if(j==2){
                        operate(light, vector<int>{1,3,5}, n);
                    }else{
                        operate(light, vector<int>{0,3}, n);
                    }
                }

                state/=2;
            }

            int tmp=0;
            for(auto num:light){
                tmp*=2;
                tmp+=num;
            }
            memo[tmp]++;
        }

        int ans=0;
        for(auto num:memo){
            if(num>0) ans++;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n1\n
// @lcpr case=end

// @lcpr case=start
// 2\n1\n
// @lcpr case=end

// @lcpr case=start
// 3\n1\n
// @lcpr case=end

 */

