/*
 * @lc app=leetcode.cn id=1203 lang=cpp
 * @lcpr version=30122
 *
 * [1203] 项目管理
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
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        // n个项目，m组
        for(int i=0;i<n;i++){
            if(group[i]==-1){
                group[i]=m;
                m++;
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<"item: "<<i<<", group: "<<  group[i]<<endl;
        // }

        vector<vector<int>> group2item(m);
        for(int i=0;i<n;i++){
            // 项目i， 组group[i]
            group2item[group[i]].push_back(i);
        }
        // for(int i=0;i<m;i++){
        //     cout<<"group: "<<i<<endl;
        //     for(int num:group2item[i])
        //         cout<<num<<",";
        //     cout<<endl;
        // }

        // 对组进行拓扑排序
        vector<set<int>> memo(m);
        vector<set<int>> ingroup_item(n);// 每组组内的排序，保证组内的一点敲好构成连通分支
        // for(int i=0;i<m;i++){
        //     ingroup_item[i].resize(group2item[i].size());
        // }
        vector<int> in(m);
        for(int i=0;i<beforeItems.size();i++){
            for(int bef_item:beforeItems[i]){
                if(group[bef_item]==group[i]){
                    ingroup_item[bef_item].insert(i);
                    continue;
                } 
                // 组内顺序，不考虑
                if(memo[group[bef_item]].find(group[i]) == memo[group[bef_item]].end()){
                    memo[group[bef_item]].insert(group[i]);
                    in[group[i]]++;
                }
                // 组间顺序，只考虑一次
            }
        }
        // for(int i=0;i<m;i++){
        //     cout<<"#"<<i<<endl;
        //     cout<<in[i]<<endl;
        // }

        deque<int> dq;
        vector<int> ans_group;
        for(int i=0;i<m;i++){
            if(in[i]==0){
                dq.push_back(i);
                ans_group.push_back(i);
            }
        }
        
        while(!dq.empty()){
            int cur=dq.front();
            dq.pop_front();
            for(int next:memo[cur]){
                in[next]--;
                if(!in[next]){
                    dq.push_back(next);
                    ans_group.push_back(next);
                }
            }
        }
        // cout<<"!!"<<endl;
        // cout<<ans_group.size()<<endl;
        // for(int i=0;i<ans_group.size();i++){
        //     cout<<ans_group[i]<<endl;
        // }
        if(ans_group.size()!=m) return {};

        vector<int> ans;
        for(int g:ans_group){
            // 组内仍然需要排序
            vector<int> ingroup_in=group2item[g];
            unordered_map<int,int> in;
            deque<int> dq;
            vector<int> tmp_ans;
            for(int i:group2item[g]){
                for(int next:ingroup_item[i]){
                    // cout<<"eg:"<<i<<"->"<<next<<endl;
                    in[next]++;
                }
            }
            for(int i:group2item[g]){
                if(in[i]==0){
                    tmp_ans.push_back(i);
                    dq.push_back(i);
                }
            }

            while(!dq.empty()){
                int cur=dq.front();
                dq.pop_front();
                for(int next:ingroup_item[cur]){
                    in[next]--;
                    if(!in[next]){
                        dq.push_back(next);
                        tmp_ans.push_back(next);
                    }
                }
            }
            if(tmp_ans.size()!=ingroup_in.size()){
                return {};

            } 
            ans.insert(ans.end(), tmp_ans.begin(), tmp_ans.end());
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 8\n2\n[-1,-1,1,0,0,1,0,-1]\n[[],[6],[5],[6],[3,6],[],[],[]]\n
// @lcpr case=end

// @lcpr case=start
// 8\n2\n[-1,-1,1,0,0,1,0,-1]\n[[],[6],[5],[6],[3],[],[4],[]]\n
// @lcpr case=end

 */

