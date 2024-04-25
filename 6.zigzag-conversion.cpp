/*
 * @lc app=leetcode.cn id=6 lang=cpp
 * @lcpr version=30122
 *
 * [6] Z 字形变换
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
    string convert(string s, int numRows) {
        if(numRows==1) return s; // 对1，此时2k-2为1，需要特殊处理

        int n=s.size();
        string ans;

        for(int i=0;i<=numRows-1;i++){
            if(i==0 || i==numRows-1){
                for(int j=i;j<n;j+=numRows*2-2){
                    ans+=string(1, s[j]);
                }
            }else{
                int left=i, right=2*numRows-2-i;
                while(left<n){
                    ans+=string(1, s[left]);
                    if(right<n){
                        ans+=string(1, s[right]);
                    }
                    left+=2*numRows-2;
                    right+=2*numRows-2;
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "PAYPALISHIRING"\n2\n
// @lcpr case=end
// @lcpr case=start
// "PAYPALISHIRING"\n3\n
// @lcpr case=end
// @lcpr case=start
// "PAYPALISHIRING"\n4\n
// @lcpr case=end
// @lcpr case=start
// "PAYPALISHIRING"\n5\n
// @lcpr case=end
// @lcpr case=start
// "PAYPALISHIRING"\n6\n
// @lcpr case=end

// @lcpr case=start
// "A"\n2\n
// @lcpr case=end
// @lcpr case=start
// "A"\n1\n
// @lcpr case=end

 */

