/*
 * @lc app=leetcode.cn id=2156 lang=cpp
 * @lcpr version=30201
 *
 * [2156] 查找给定哈希值的子串
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
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        // 使用滑动窗口和秦九韶公式避免重复运算
        // 避免找m的逆元，选择反向遍历
        int rt=s.size()-1, lt=s.size()-1;
        long long val=0, tail=1;
        int loc=-1;

        for(int i=1;i<k;i++){
            tail*=power;
            tail%=modulo;
        }
        while(lt>= (int)s.size()-k){ // 如果减去需要手动转化，否则
        // (int)-1 >= (unsigned int)0会成立，因为会将-1转化为4294967295
            val*=power;
            val%=modulo;
            val+=s[lt]-'a'+1;
            val%=modulo;
            lt--;
        }
        if(val==hashValue) loc=lt+1; // 这里是左开右闭

        while(lt>=0){
            val-=((s[rt]-'a'+1)*tail)%modulo;
            val=(val+modulo)%modulo;
            
            val*=power;
            val%=modulo;
            val+=s[lt]-'a'+1;
            val%=modulo;
            if(val==hashValue) loc=lt;   // 这里是左闭右开

            rt--;
            lt--;
        }
        return s.substr(loc, k);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "xmmhdakfursinye"\n96\n45\n15\n21\n
// @lcpr case=end
// @lcpr case=start
// "leetcode"\n7\n20\n2\n0\n
// @lcpr case=end

// @lcpr case=start
// "fbxzaad"\n31\n100\n3\n32\n
// @lcpr case=end

 */

