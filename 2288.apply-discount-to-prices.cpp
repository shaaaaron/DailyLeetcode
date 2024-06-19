/*
 * @lc app=leetcode.cn id=2288 lang=cpp
 * @lcpr version=30203
 *
 * [2288] 价格减免
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
    string discountPrices(string sentence, int discount) {

        int i=0, j;
        string ans;
        while(i<sentence.size()){
            j=i;
            int flag= sentence[i]=='$'?1:0; // 表示是浮点数
            while(j<sentence.size() && sentence[j]!=' '){
                if(j>i && (sentence[j]=='$' || sentence[j]>='a' && sentence[j]<='z')) flag=0;
                j++;
            }
            // 除了$还需要至少一个数字
            if(flag==1 && j==i+1) flag=0;

            if(flag == 0){
                ans += sentence.substr(i, j-i);
            }else{
                long long num=0;
                ans+='$';
                for(int k=i+1;k<j;k++){//
                    num=num*10+sentence[k]-'0';
                    // cout<<num<<endl;
                }
                long long tmp=num;

                num=num*(100-discount)/100;
                ans+=to_string(num);
                ans+='.';

                ans+=tmp*(100-discount)/10%10+'0'; // double无法表示范围，所以使用longlong，但是（使用整数乘法）手动计算小数点后面的位数
                ans+=tmp*(100-discount)%10+'0';
            }
            if(j<sentence.size())
                ans+=' ';
            i=j+1;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "there are $1 $2 and 5$ candies in the shop"\n50\n
// @lcpr case=end

// @lcpr case=start
// "1 2 $3 4 $5 $6 7 8$ $9 $10$"\n100\n
// @lcpr case=end
// @lcpr case=start
// "$76111 ab $6 $"\n48\n
// @lcpr case=end
// @lcpr case=start
// "706hzu76jjh7yufr5x9ot60v149k5 $765191 pw2o $6"\n28
// @lcpr case=end
// @lcpr case=start
// "706hzu76jjh7yufr5x9ot60v149k5 $7651913 pw2o $6"\n28
// @lcpr case=end
// @lcpr case=start
// "706hzu76jjh7yufr5x9ot60v149k5 $76519131 pw2o $6"\n28
// @lcpr case=end
// @lcpr case=start
// "706hzu76jjh7yufr5x9ot60v149k5 $765191318 pw2o $6"\n28
// @lcpr case=end
// @lcpr case=start
// "706hzu76jjh7yufr5x9ot60v149k5 $7651913186 pw2o $6"\n28
// @lcpr case=end

 */

