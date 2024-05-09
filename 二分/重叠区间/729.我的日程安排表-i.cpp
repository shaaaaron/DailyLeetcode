/*
 * @lc app=leetcode.cn id=729 lang=cpp
 * @lcpr version=30201
 *
 * [729] 我的日程安排表 I
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
class MyCalendar {
public:
    set<pair<int,int>> cal;
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        auto it=cal.lowerbound(make_pair(end, 0)); // 
        if(it!=cal.end() && end>prev(it)->first){
            return false;
        }
        cal.insert(make_pair(start, end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end



/*
// @lcpr case=start
// ["MyCalendar", "book", "book", "book"][[], [10, 20], [15, 25], [20, 30]]\n
// @lcpr case=end

 */

