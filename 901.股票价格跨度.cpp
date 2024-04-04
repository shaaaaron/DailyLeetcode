/*
 * @lc app=leetcode.cn id=901 lang=cpp
 * @lcpr version=30121
 *
 * [901] 股票价格跨度
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
class StockSpanner {
public:
    vector<int> stock;
    stack<int> s;
    StockSpanner() {
    }
    
    int next(int price) {
        // 维护一个小顶单调栈，目的不是让每个元素见到右边最大
        // 而是每个元素进栈的时候，见到最右边比自己大的
        stock.push_back(price); // 先数组再栈
        while(!s.empty() && stock[s.top()]<=price){ //上一个大于的就是跨度
            s.pop();
        }
        int ans=s.empty() ? stock.size(): stock.size()-1-s.top();
        
        s.push(stock.size()-1);

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end



/*
// @lcpr case=start
// ["StockSpanner", "next", "next", "next", "next", "next", "next", "next"][[], [100], [80], [60], [70], [60], [75], [85]]\n
// @lcpr case=end

 */

