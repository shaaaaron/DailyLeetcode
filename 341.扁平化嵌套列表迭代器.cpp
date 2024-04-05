/*
 * @lc app=leetcode.cn id=341 lang=cpp
 * @lcpr version=30121
 *
 * [341] 扁平化嵌套列表迭代器
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
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const{}
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const{}
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const{}
};

// 不能重定义
// 使用迭代器

class NestedIterator {
public: 
    vector<int> flattenList;
    int i;

    NestedIterator(vector<NestedInteger> &nestedList) { // 输入的默认是vector
        flattenList=dfs(nestedList);
        i=0;// 下一个要遍历的元素
    }
    
    vector<int> dfs(vector<NestedInteger> &nestedList) {
        vector<int> ans;

        for(auto & subobj:nestedList){
            if(subobj.isInteger()){
                ans.push_back(subobj.getInteger()); // 可以直接将结果放到val数组，不用再dfs赋值
            }else{
                vector<int> tmp=dfs(subobj.getList()); // 不能见const传给非const函数。但是leetcode不会报错
                for(auto num:tmp){
                    ans.push_back(num);
                }
            }
        }

        return ans;
    }

    int next() {
        int ans =flattenList[i];
        i++;
        return ans;
    }
    
    bool hasNext() {
        return i<flattenList.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end



/*
// @lcpr case=start
// [[1,1],2,[1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [1,[4,[6]]]\n
// @lcpr case=end

 */

