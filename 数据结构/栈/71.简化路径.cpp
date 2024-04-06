/*
 * @lc app=leetcode.cn id=71 lang=cpp
 * @lcpr version=30121
 *
 * [71] 简化路径
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
// 从根目录向上移动依然是根目录
    string simplifyPath(string path) {
        stack<string> s;
        int n=path.size();
        int i=0,j;
        while(i<n){
            if(path[i] != '/'){ //不是以斜杠为边界的子串，而是都不为边界的子串，更好实现
                j=i;
                while(j<n && path[j]!='/'){
                    j++;
                }j--;//实际的边界，[i,j]是不含斜杠的子串
                //substr长度为非负数，因为类型是size_t
                string command=path.substr(i,j-i+1);

                if(command=="."){

                }else if(command == ".."){
                    if(!s.empty()){
                        s.pop();
                    }
                }else{
                    s.push(command);
                }

                i=j;
            }
            i++;
        }

        if(s.empty()) return "/";

        string ans="";
        while(!s.empty()){
            ans="/"+s.top()+ans; //拼接特性就可以，不用reverse
            s.pop();
        }        
        // 最后的/，如果是根目录保留否则去除
        // 根目录向上返回依然是们目录
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "/home/"\n
// @lcpr case=end

// @lcpr case=start
// "/../"\n
// @lcpr case=end

// @lcpr case=start
// "/home//foo/"\n
// @lcpr case=end

// @lcpr case=start
// "/a/./b/../../c/"\n
// @lcpr case=end

 */

