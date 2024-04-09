/*
 * @lc app=leetcode.cn id=636 lang=cpp
 * @lcpr version=30121
 *
 * [636] 函数的独占时间
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
    int convert(string str){
        int ans=0;
        for(int i=0;i<str.size();i++){
            ans*=10;
            ans+=str[i]-'0';
        }
        return ans;
    }

    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n,0);
        stack<pair<int,int>> s; // 栈不仅存正在匹配的工作，还存匹配中的工作

        for(auto str:logs){
            int colon1=-1,colon2=-1;
            for(int i=0;i<str.size();i++){
                if(str[i]==':' && colon1 ==-1){
                    colon1=i;
                }else if(str[i]==':'){
                    colon2=i;
                }
            }

            int taskid=convert(str.substr(0,colon1));
            int time=convert(str.substr(colon2+1));
            if(str.substr(colon1+1,colon2-colon1-1) == "start"){
                s.push(make_pair(taskid, time));
            }else{
                int len=0;
                if(s.top().first<0){
                    len = s.top().first;
                    s.pop();
                }
                if(!s.empty() && s.top().first==taskid){
                    ans[taskid]+=(time-s.top().second+1 +len);
                    len=-(time-s.top().second+1);
                    s.pop();
                    if(!s.empty() && s.top().first<0){
                        s.top().first+=len;///
                    }else{
                        s.push(make_pair(len,0));
                    }
                }
            }
        }

        return ans;

    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n["0:start:0","1:start:2","1:end:5","0:end:6"]\n
// @lcpr case=end

// @lcpr case=start
// 1\n["0:start:0","0:start:2","0:end:5","0:start:6","0:end:6","0:end:7"]\n
// @lcpr case=end

// @lcpr case=start
// 2\n["0:start:0","0:start:2","0:end:5","1:start:6","1:end:6","0:end:7"]\n
// @lcpr case=end

// @lcpr case=start
// 2\n["0:start:0","0:start:2","0:end:5","1:start:7","1:end:7","0:end:8"]\n
// @lcpr case=end

// @lcpr case=start
// 1\n["0:start:0","0:end:0"]\n
// @lcpr case=end

 */

