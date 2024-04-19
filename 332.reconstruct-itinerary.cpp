/*
 * @lc app=leetcode.cn id=332 lang=cpp
 * @lcpr version=30122
 *
 * [332] 重新安排行程
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
// 很有趣的题目，下面的代码不是最终的代码，而是v1和v2
// v1遍历所有情况，和ans进行比较选最小的
// v2首先进行排序，所以搜到了直接return true返回，余下的不需要搜索
// leetcode网页上提交的v3，对于多个相同的方案聚合成一张票，继续剪纸

        // 由于默认构造函数，不需要再第一次访问显示初始化
        // for (const auto& ticket : tickets) {
        //     flightMap[ticket[0]][ticket[1]]++;
        // }
class Solution {
public:
    unordered_map<string, vector< pair<int,string>>> map;
    vector<int> visited;

    vector<string> now;

    vector<string> ans;

    // bool check(vector<string> &x, vector<string>& y){ // check x<y
    //     for(int i=0;i<x.size()&&i<y.size();i++){
    //         if(x[i]<y[i])return true;
    //         if(x[i]>y[i])return false;
    //     }
    //     if(x.size()<y.size()) return true;
    //     return false;
    // }

    bool bt(){ // 表示是否找到
        // 所有机票必须用且只用一次
        if(now.size()-1==visited.size()){ //此时才终止
            // if(ans.size()==0 || check(now, ans)){ //空串是最小的
            //     ans=now;
            // }
            ans=now;
            return true;
        }

        // 如果已经有路程，而且比之大了
        // if(ans.size()!=0 && !check(now,ans)){ //不能写反
        //     return;
        // }


        for(auto &pr:map[now.back()]){
            int i=pr.first;
            string des=pr.second;

            if(visited[i]) continue;

            now.push_back(des);
            visited[i]=true;

            if(bt())return true;

            now.pop_back();
            visited[i]=false;
        }
        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(int i=0;i<tickets.size();i++){
            vector<string> &tmp=tickets[i];

            if(map.find(tmp[0])==map.end()){
                map[tmp[0]]=vector< pair<int,string>>{};
            }

            map[tmp[0]].push_back(make_pair(i, tmp[1]));
        }

        for(auto &m : map){
            sort(m.second.begin(), m.second.end(), [](const pair<int, string> &a, const pair<int, string> &b){
                return a.second < b.second;
            });
        }

        visited.resize(tickets.size());
        for(int i=0;i<visited.size();i++) visited[i]=false;

        now.push_back("JFK");
        bt();
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]\n
// @lcpr case=end

// @lcpr case=start
// [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]\n
// @lcpr case=end

 */



// class Solution {
// public:
//     unordered_map<string, map<string, int>> flightMap;

//     bool backtracking(const string& airport, vector<string>& itinerary, int ticketsUsed, int totalTickets) {
//         if (ticketsUsed == totalTickets) {
//             return true;  // 所有机票都已使用
//         }

//         for (auto& [nextAirport, count] : flightMap[airport]) {
//             if (count > 0) {  // 检查是否还有剩余的未使用航班
//                 itinerary.push_back(nextAirport);
//                 count--;  // 使用一张航班
//                 if (backtracking(nextAirport, itinerary, ticketsUsed + 1, totalTickets)) {
//                     return true;
//                 }
//                 itinerary.pop_back();
//                 count++;  // 回溯，恢复航班
//             }
//         }
//         return false;
//     }

//     vector<string> findItinerary(vector<vector<string>>& tickets) {
//         for (const auto& ticket : tickets) {
//             flightMap[ticket[0]][ticket[1]]++;
//         }
//         vector<string> itinerary = {"JFK"};
//         backtracking("JFK", itinerary, 0, tickets.size());
//         return itinerary;
//     }

// };
