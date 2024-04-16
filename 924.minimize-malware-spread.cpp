/*
 * @lc app=leetcode.cn id=924 lang=cpp
 * @lcpr version=30122
 *
 * [924] 尽量减少恶意软件的传播
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
    vector<int> p;
    
    int find(int a){
        if(p[a] == a) return a;
        return p[a]=find(p[a]);
    }
    
    void merge(int a, int b){
        p[find(a)]=find(b);
    }
    
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        sort(initial.begin(), initial.end()); // 保证小的节点在前面
         
        int n=graph.size();
        p.resize(n); // 大小初始化
        for(int i=0;i<n;i++){
            p[i]=i;
        }
        
        vector<int> branch_node_nums(n, 0); // 分支对应的节点中，在代表节点记录分支的信息    
        vector<int> branch_p_nums(n, 0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(graph[i][j]==1){
                    merge(i,j);
                }
            }
        }
        
        // 经过一次find，每个节点都指向最高的祖先，也就是每个连通分支的代表元素
        for(int i=0;i<n;i++){
            branch_node_nums[find(i)]++;
        }
        
        // 下面p[i]就能找到连通分支的代表元素，当然也可以使用find
        for(int i=0;i<initial.size();i++){
            branch_p_nums[ p[initial[i]] ]++;
        }
        
        int idx=-1;
        // 如果有只有一个病毒的连通分支，则选取其中最大分支的病毒。选择索引最小的
        for(int i=0;i<initial.size();i++){
            int node_id = initial[i];
            int branch_id = p[node_id];
            
            if( !(branch_p_nums[branch_id]==1) ) continue; // 有多个病毒或者不存在病毒
            // !的优先级是什么
            // 如果当前只有一个，则查看
            if(idx==-1 || branch_node_nums[branch_id]>branch_node_nums[p[idx]]){
                idx=node_id;
            }
        }
    
        if(idx!=-1){
            return idx;
        }
        
        // 否则返回其中最小的
        return initial[0];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,1,0],[1,1,0],[0,0,1]]\n[0,1]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,0],[0,1,0],[0,0,1]]\n[0,2]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,1],[1,1,1],[1,1,1]]\n[1,2]\n
// @lcpr case=end

 */

