/*
 * @lc app=leetcode.cn id=2056 lang=cpp
 * @lcpr version=30201
 *
 * [2056] 棋盘上有效移动组合的数目
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
    typedef pair<int,int> PII;
    const int LEN=8;
    int n;

    vector<PII> bish_act;
    vector<PII> rook_act;
    vector<PII> quee_act;

    vector<string> pieces;
    vector<vector<int>> positions;

    int map[10][10][10]; // 可以访问0到7,如果在外面初始化为静态成员变量，没有效果
    
    int dfs(int index){
        if(index>=n){
            // cout<<"***"<<endl;
            // for(int i=1;i<=2;i++){
            //     cout<<"time"<<i<<endl;
            //     for(int j=0;j<3;j++){
            //         for(int k=0;k<3;k++){
            //             cout<<map[i][j][k];
            //         }
            //     cout<<endl;
            //     }
            // }
            return 1;
        }  
        // 直接开始等待
        cout<<index<<endl;
        int x=positions[index][0]-1, y=positions[index][1]-1;
        int flag=0;
        for(int i=1;i<LEN;i++) // 第一步一定不重合，不需要记录
            if(map[i][x][y])
                flag=1;
        
        int ans=0;
        if(flag==0){
            for(int i=1;i<LEN;i++) // 第一步一定不重合，不需要记录
                map[i][x][y]=index+1;
            ans+=dfs(index+1);
            for(int i=1;i<LEN;i++)
                map[i][x][y]=0; 
        }
        
        vector<PII>* act; // 引用是不能切换绑定的，使用指针
        if(pieces[index]=="q"){
            act=&quee_act;
        }else if(pieces[index]=="r"){
            act=&rook_act;
        }else{
            act=&bish_act;
        }
        for(auto [dx, dy]: *act){
            int i;
            for(i=1;i<LEN;i++){// 最多行动7步
                int next_x=x+dx*i, next_y=y+dy*i; // 难绷dy写成dx了
                if(next_x<0 || next_x>=LEN || next_y<0 || next_y>=LEN)
                    break;
                if(map[i][next_x][next_y])
                    // 之后的走不通了
                    break;   

                map[i][next_x][next_y]=index+1;
                
                // 看看能不能停留在当前位置
                bool conflict=false;
                for(int j=i+1;j<LEN;j++)
                    if(map[j][next_x][next_y]){
                        conflict=true;
                        continue;
                    }
                if(conflict) continue;
                for(int j=i+1;j<LEN;j++){
                    map[j][next_x][next_y]=index+1;
                }
                ans+=dfs(index+1);
                for(int j=i+1;j<LEN;j++){
                    map[j][next_x][next_y]=0;
                }
            }
            
            for(int j=1;j<i;j++){
                map[j][x+dx*j][y+dy*j]=0;
            }
        }
        return ans; 
    };

    int countCombinations(vector<string>& pieces, vector<vector<int> >& positions) {
        n=pieces.size();

        bish_act=vector<PII> {{-1,-1},{-1,1},{1,1},{1,-1}};
        rook_act=vector<PII> {{0 , 1},{0,-1},{-1,0},{1,0}};
        quee_act=vector<PII> {{-1,-1},{-1,1},{1,-1},{1,1},
            {0 , 1},{0,-1},{-1,0},{1,0}
        };

        for(int i=0;i<n;i++){
            if(pieces[i][0]=='r') pieces[i]="r";
            else if(pieces[i][0]=='q') pieces[i]="q";
            else pieces[i]="b";
        }
        
        this->pieces=pieces;
        this->positions=positions;

        memset(map, 0, sizeof(map));
        // fill(&map[0][0][0], &map[0][0][0] + sizeof(map) / sizeof(map[0][0][0]), 0);
        return dfs(0);
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["queen", "bishop"]\n[[8,5],[7,7]]\n
// @lcpr case=end
// @lcpr case=start
// ["queen", "bishop"]\n[[7,5],[7,7]]\n
// @lcpr case=end
// @lcpr case=start
// ["queen", "bishop"]\n[[8,6],[7,7]]\n
// @lcpr case=end
// @lcpr case=start
// ["queen", "bishop"]\n[[7,5],[7,3]]\n
// @lcpr case=end
// @lcpr case=start
// ["queen", "rook"]\n[[8,5],[8,1]]\n
// @lcpr case=end
// @lcpr case=start
// ["queen", "rook"]\n[[8,5],[7,7]]\n
// @lcpr case=end
// @lcpr case=start
// ["queen", "rook"]\n[[8,5],[7,7]]\n
// @lcpr case=end
// @lcpr case=start
// ["bishop", "rook"]\n[[8,5],[7,7]]\n
// @lcpr case=end
// @lcpr case=start
// ["bishop", "bishop"]\n[[2,2],[1,1]]\n
// @lcpr case=end
// @lcpr case=start
// ["bishop", "bishop"]\n[[1,1],[2,2]]\n
// @lcpr case=end
// @lcpr case=start
// ["rook"]\n[[1,1]]\n
// @lcpr case=end

// @lcpr case=start
// ["queen"]\n[[1,1]]\n
// @lcpr case=end

// @lcpr case=start
// ["bishop"]\n[[4,3]]\n
// @lcpr case=end

// @lcpr case=start
// ["rook","rook"]\n[[1,1],[8,8]]\n
// @lcpr case=end

// @lcpr case=start
// ["queen","bishop"]\n[[5,7],[3,4]]\n
// @lcpr case=end

 */


int main() {
    Solution s;
    vector<string> p1{"bishop", "bishop"};
    vector<vector<int> > p2{ vector<int>{2,2},  vector<int>{1,1}};
    cout<<s.countCombinations(p1,p2)<<endl;
    vector<vector<int> > p3{ vector<int>{1,1},  vector<int>{2,2}};
    cout<<s.countCombinations(p1,p3)<<endl;
    cout<<"***"<<endl;
    return 0;
}
