/*
 * @lc app=leetcode.cn id=1598 lang=cpp
 * @lcpr version=30121
 *
 * [1598] 文件夹操作日志搜集器
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
    int minOperations(vector<string>& logs) {
        int num=0; // 只需要记录数量，不需要栈
        for(auto & str:logs){
            if(num!=0 && str=="../"){
                num--;
            }else if(str !="../" && str !="./"){
                num++;
            }
        }

        return num;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["d1/","d2/","../","d21/","./"]\n
// @lcpr case=end

// @lcpr case=start
// ["d1/","d2/","./","d3/","../","d31/"]\n
// @lcpr case=end

// @lcpr case=start
// ["d1/","../","../","../"]\n
// @lcpr case=end

 */

