/*
 * @lc app=leetcode.cn id=2069 lang=cpp
 * @lcpr version=30122
 *
 * [2069] 模拟行走机器人 II
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
class Robot {
public:
    int x,y;
    int dir; // 0123,东南西北

    vector<pair<int,int>> dirs;
    int width, height;
    Robot(int width, int height) {
        x=y=0;
        dir=0;

        dirs=vector<pair<int,int>>{{1,0}, {0,-1}, {-1,0}, {0,1}};

        this->width=width;
        this->height=height;
    }
    
    void step(int num) {
        while(num>0){
            // num=num%(2*width+2*height-4); 不能这里直接消除，因为并且在边框上且顺着方向
            
            int dx=dirs[dir].first,dy=dirs[dir].second;
            while(x+dx<0 || x+dx>=width || y+dy<0 || y+dy>=height){ // 首先找到可行的方向,至少能走一步
                dir=(dir+3)%4;
                dx=dirs[dir].first,dy=dirs[dir].second;
            }

            int step;
            if(dir==0){
                step=min(num, width-x-1);
            }else if(dir==1){
                step=min(num, y);
            }else if(dir==2){
                step=min(num, x);
            }else{
                step=min(num, height-y-1);
            }
            
            x+=step*dx;
            y+=step*dy;
            num-=step;

            if(y==0&&dir==0 || x==width-1&&dir==3 || y==height-1&&dir==2 ||
                x==0&&dir==1){ // 只有在边界上顺着走，才可以直接消除
                num=num%(2*width+2*height-4);
            }
        }
    }
    
    vector<int> getPos() {
        return vector<int>{x,y};
    }
    
    string getDir() {
        if(dir==0) return "East";
        if(dir==1) return "South";
        if(dir==2) return "West";
        return "North"; // 自动字符串到string转化
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
// @lc code=end



/*
// @lcpr case=start
// ["Robot", "step", "step", "getPos", "getDir", "step", "step", "step", "getPos", "getDir"][[6, 3], [2], [2], [], [], [2], [1], [4], [], []]\n
// @lcpr case=end

 */

