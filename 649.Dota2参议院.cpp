/*
 * @lc app=leetcode.cn id=649 lang=cpp
 * @lcpr version=30121
 *
 * [649] Dota2 参议院
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
    string predictPartyVictory(string senate) {
        deque<char> q;
        int Rnum=0, Dnum=0;
        for(auto ch:senate){
            q.push_back(ch);
            if(ch=='R'){
                Rnum++; // 存储一下什么时候结束
            }else{
                Dnum++;
            }
        }

        int votes=0; // 正数是D
        while(q.size()>=2){
            if(votes>0){
                if(q.front()=='D'){ // 逻辑有点复杂，看看能不能改
                    votes++;
                    int tmp=q.front();
                    q.pop_front();
                    q.push_back(tmp);
                }else{
                    votes--;
                    Rnum--;
                    q.pop_front();
                }
            }else if(votes<0){
                if(q.front()=='D'){
                    votes++;
                    Dnum--;
                    q.pop_front();
                }else{
                    votes--;                    
                    int tmp=q.front();
                    q.pop_front();
                    q.push_back(tmp);
                }  
            }else{
                if(q.front()=='D'){
                    votes++;
                    int tmp=q.front();
                    q.pop_front();
                    q.push_back(tmp);
                }else{
                    votes--;                    
                    int tmp=q.front();
                    q.pop_front();
                    q.push_back(tmp);
                } 
            }

            if(Rnum==0) return "Dire";
            if(Dnum==0) return "Radiant";
        }
        return q.front()=='D' ?"Dire":"Radiant"; // 其实走不到这里，只是防止C++报错
    }
};
// @lc code=end



/*
// @lcpr case=start
// "RD"\n
// @lcpr case=end

// @lcpr case=start
// "RDD"\n
// @lcpr case=end

 */

