/*
 * @lc app=leetcode.cn id=726 lang=cpp
 * @lcpr version=30121
 *
 * [726] 原子的数量
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

    // 效率有点低，用了map、vec、str
    // 变量名应该有逻辑
    string countOfAtoms(string formula) {
        stack<unordered_map<string,int>> s; // 存储原子和数量
                                            // aA 不合法的名称

        int i=0,j ,n=formula.size();
        while(i<n){
            j=i;
            if(formula[i]=='('){
                s.push(unordered_map<string,int>{ {"(",0} });
            }else if(formula[i]==')'){
                // 将stack之间的所有数合并到一起
                unordered_map<string,int> tmp;
                while(s.top().find("(") == s.top().end()){ // 不能反了
                    for(auto element: s.top()){ // 这样是pair； begin是迭代器
                        tmp[element.first]+=element.second;
                    }
                    s.pop();
                }
                s.pop();
                s.push(tmp);
            }else if(formula[i]>='0' && formula[i]<='9'){ // 反了
                while(j<n && formula[j]>='0' && formula[j]<='9'){ // 变量名
                    j++;
                }j--;
                int num=convert(formula.substr(i,j-i+1));
                for(auto element: s.top()){
                    s.top()[element.first]*=num;
                }
                i=j;
            }else{
                j=i;
                while(j<n && (i==j && formula[j]>='A' && formula[j]<='Z' || i<j && formula[j]>='a' && formula[j]<='z')){
                    j++;
                }j--;

                s.push(unordered_map<string,int>{{formula.substr(i,j-i+1),1}});
                i=j;
            }
            i++;
        }

        unordered_map<string,int> memo;
        while(!s.empty()){
            for(auto pair: s.top()){
                memo[pair.first]+=pair.second;
            }
            s.pop();
        }

        vector< pair<string,int>> ans;
        for(auto & pr: memo){
            ans.push_back(pr);
        }
        sort(ans.begin(), ans.end(), [](auto &tp1, auto& tp2){
            return get<0>(tp1)<get<0>(tp2);
        });

        string ansstr;
        for(auto& tp: ans){
            ansstr+=  get<1>(tp)!=1 ? get<0>(tp)+to_string(get<1>(tp)) : get<0>(tp);
        }
        return ansstr;
    }
};
// @lc code=end



/*

// @lcpr case=start
// "K4(ON(SO3)2)2(OH)2Mg(OH)2H2OEaaaaa123"\n
// @lcpr case=end
// @lcpr case=start
// "(OH)2"\n
// @lcpr case=end
// @lcpr case=start
// "H2O"\n
// @lcpr case=end

// @lcpr case=start
// "Mg(OH)2"\n
// @lcpr case=end

// @lcpr case=start
// "K4(ON(SO3)2)2"\n
// @lcpr case=end

 */

