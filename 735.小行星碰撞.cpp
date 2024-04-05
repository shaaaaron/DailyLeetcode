/*
 * @lc app=leetcode.cn id=735 lang=cpp
 * @lcpr version=30121
 *
 * [735] 小行星碰撞
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
// 方便起见用了两个，其实只需要一个
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        vector<int> ans;

        for(auto mass:asteroids){
            if(mass>0){
                s.push(mass);
            }else if(mass<0 && s.empty()){
                ans.push_back(mass);
            }else if(mass<0 && !s.empty()){
                while(!s.empty() ){ // 一直撞
                    if(s.top()< -mass){
                        s.pop();
                    }else if(s.top()== -mass){
                        s.pop();
                        mass=0;             // 如果同归于尽了
                        break;
                    }else if(s.top()> -mass){
                        mass=0;             // 如果同归于尽了
                        break;
                    }
                }
                if(mass!=0){ // mass是负数和0来判断
                    ans.push_back(mass);
                }
            }
        }

        vector<int> tmp;
        while(!s.empty()){
            tmp.push_back(s.top());
            s.pop();
        }
        
        for(auto iter=tmp.rbegin();iter!=tmp.rend();iter++){
            ans.push_back(*iter);
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-2,-1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [8,-8]\n
// @lcpr case=end

// @lcpr case=start
// [10,2,-5]\n
// @lcpr case=end

 */

