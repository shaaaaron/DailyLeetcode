/*
 * @lc app=leetcode.cn id=705 lang=cpp
 * @lcpr version=30122
 *
 * [705] 设计哈希集合
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
class MyHashSet {
public:
    const int CONSTANT=0xcaffee;
    const int len=10000;
    vector<vector<int>> hashset;
    // runtime error: applying non-zero offset 24 to null pointer (stl_vector.h) SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior 如果访问越界有这个问题

    MyHashSet() {
        hashset.resize(len);
    }
    
    int compute_hash(int key){
        long long x=key;
        return  ((x << 15) | (x >> (32 - 15))^ CONSTANT) % len;
        // 运算后括号，然后取模
    }

    void add(int key) {
        int hash_num = compute_hash(key);
        for (auto iter = hashset[hash_num].begin(); iter != hashset[hash_num].end(); ++iter) {
            if (*iter == key) {
                // Key already exists, do not add it again.
                return;
            }
        }
        hashset[hash_num].push_back(key);
    }
    
    void remove(int key) {
        int hash_num = compute_hash(key);
        for(auto iter=hashset[hash_num].begin(); iter!=hashset[hash_num].end(); iter++){
            if(*iter == key){
                hashset[hash_num].erase(iter);
                break;
            }
        }
    }
    
    bool contains(int key) {
        int hash_num = compute_hash(key);
        for(auto & num: hashset[hash_num]){
            if(num==key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end



/*
// @lcpr case=start
// ["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"][[], [1], [2], [1], [3], [2], [2], [2], [2]]\n
// @lcpr case=end

 */

