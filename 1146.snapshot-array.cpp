/*
 * @lc app=leetcode.cn id=1146 lang=cpp
 * @lcpr version=30122
 *
 * [1146] 快照数组
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
class SnapshotArray {
public:
// 核心是注意到，一次只对一个元素做set、get
// 重要的是各种 细节的处理
    int snap_id;
    unordered_map<int,vector<pair<int, int>>> memo;

    SnapshotArray(int length) {
        snap_id=0;
    }
    
    void set(int index, int val) {
        if(memo.find(index)==memo.end()){
            memo[index]=vector<pair<int, int>>{};
        }
        auto& tmp = memo[index];
        if(tmp.size()>=1 && tmp.back().first==snap_id){//
            tmp.back().second=val;
        }else{
            tmp.push_back({snap_id, val});
        }
    }
    
    int snap() {
        snap_id++; // 后面的都是这个快照
        return snap_id-1; // 上一个快照号
    }
    
    // memo中存放的未必是连续的snapid，找到小于等于snap_id的第一个
    int get(int index, int snap_id) {
        if(memo.find(index)==memo.end()) return 0; // 

        auto& tmp = memo[index]; // 至少一个元素
        int lt=0, rt=tmp.size()-1;
        while(lt<=rt){
            int md=(lt+rt)/2;
            if(tmp[md].first>snap_id){
                rt=md-1;
            }else{
                lt=md+1;
            }
        }

        if(rt<0) return 0;//
        return tmp[rt].second;//
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
// @lc code=end



/*
// @lcpr case=start
// ["SnapshotArray","set","snap","set","get"][[3],[0,5],[],[0,6],[0,0]]\n
// @lcpr case=end

 */

