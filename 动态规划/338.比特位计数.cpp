/*
 * @lc app=leetcode.cn id=338 lang=cpp
 * @lcpr version=30121
 *
 * [338] 比特位计数
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
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        if(n==0) return ans;
        
        ans[0]=0;
        int tmpLen=1; // 当前数的长度为1 
        while(1){
            for(int i=1<<(tmpLen-1); i<= (1<<tmpLen) -1;i++){ // c++的左移位数必须是非负的，不能左移-1
                if(i>n){
                    return ans;
                }
                ans[i] = ans[i-(1<<(tmpLen-1))]+1; // 运算顺序
            }
            tmpLen++;
        }

        return ans; // 实际不会用到这里
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n
// @lcpr case=end
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 5\n
// @lcpr case=end

 */


int main() {
    int n ;
    cin >> n;
    vector<int> ans = Solution().countBits(n);
    for(int i=0;i<=n;i++){
        cout<< ans[i]<<", ";
    }
    return 0;
}
