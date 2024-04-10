/*
 * @lc app=leetcode.cn id=1702 lang=cpp
 * @lcpr version=30122
 *
 * [1702] 修改后的最大二进制字符串
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
    string maximumBinaryString(string binary) {
        // 查看一下find和count操作，c++和python的
        int n=binary.size();
        int one_num=0;
        for(auto ch:binary){
            if(ch=='1'){
                one_num++;
            }
        }
        int zero_num=n-one_num;

        if(zero_num==1 || zero_num==0){    // 一个0就不变
            return binary;
        }

        int first_one_num=0;    // 1的数量
        for(auto ch:binary){
            if(ch=='1'){
                first_one_num++;
            }else{
                break;
            }
        }

        int last_one_num=one_num-first_one_num;
        first_one_num = first_one_num+(zero_num-1);
        zero_num=1;
        return string(first_one_num,'1') + string(zero_num,'0')+string(last_one_num, '1');
        // 能否为0
    }
};
// @lc code=end



/*
// @lcpr case=start
// "000110"\n
// @lcpr case=end

// @lcpr case=start
// "01"\n
// @lcpr case=end


// @lcpr case=start
// "1"\n
// @lcpr case=end
// @lcpr case=start
// "00"\n
// @lcpr case=end
// @lcpr case=start
// "1001"\n
// @lcpr case=end
 */

