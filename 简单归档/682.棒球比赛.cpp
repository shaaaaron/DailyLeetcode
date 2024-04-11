/*
 * @lc app=leetcode.cn id=682 lang=cpp
 * @lcpr version=30122
 *
 * [682] 棒球比赛
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
    int convert(string str){    // 长度至少为1
        if(str[0]=='-'){
            return -convert(str.substr(1));
        }

        int ans=0;
        for(auto ch:str){
            ans*=10;
            ans+=ch-'0';
        }
        cout<<ans<<endl;
        return ans;
    }

    int calPoints(vector<string>& operations) {
        stack<int> st;   //由于没有优先级，直接按顺序
        for(auto &str:operations){
            if(str=="C"){
                st.pop();
            }else if(str=="D"){
                int x=st.top();
                st.push(2*x);
            }else if(str=="+"){
                int x=st.top();
                st.pop();
                int y=st.top();
                st.push(x);
                st.push(x+y);
            }else{
                st.push(convert(str));
            }
        }

        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["5","2","C","D","+"]\n
// @lcpr case=end

// @lcpr case=start
// ["5","-2","4","C","D","9","+","+"]\n
// @lcpr case=end

// @lcpr case=start
// ["1"]\n
// @lcpr case=end

 */

