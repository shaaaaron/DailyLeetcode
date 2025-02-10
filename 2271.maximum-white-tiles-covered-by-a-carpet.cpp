/*
 * @lc app=leetcode.cn id=2271 lang=cpp
 * @lcpr version=30204
 *
 * [2271] 毯子覆盖的最多白色砖块数
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
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        // 性质：
        // 1、在空白位置放置，不如在后面的下一个tile开始处放置
        // 2、在tiel中段放置，不如在当前的瓷砖开始处放置
        auto cmp = [](auto& x, auto &y){
            return x[0]<y[0];
        };

        // 如果当前结尾不是瓷砖（是-1）
        // 如果还是没有超过当前所在的瓷砖的结尾，
        // 如果超过了当前瓷砖
        //      是否有下一块瓷砖
        //      是否到达了下一块瓷砖
        sort(tiles.begin(), tiles.end(), cmp);
        int ans = 0, cnt = 0;
        int j = -1, loc_j = -1;   // 记录上一次最远能达到的瓷砖和位置
        for(int i=0; i<tiles.size(); i++){
            // tlies[i][0] + carpetLen - 1 是能达到的最远的位置
            // 处理左端点跳过的瓷砖
            if(i!=0){
                cnt -= tiles[i][1] - tiles[i][0] +1;
            }

            // 处理右端点新增的瓷砖
            int last_finished = loc_j;
            while(j+1<tiles.size() && tiles[i][0] + carpetLen - 1 >= tiles[j][0]){
                j++;
                cnt += min(tiles[i][0] + carpetLen - 1, tiles[j][1]) - max(last_finished + 1, tiles[j][0]) + 1;
                last_finished = min(tiles[i][0] + carpetLen - 1, tiles[j][1]);
            }
            loc_j = tiles[i][0] + carpetLen - 1;

            ans = max(ans, cnt);
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,5],[10,11],[12,18],[20,25],[30,32]]\n10\n
// @lcpr case=end

// @lcpr case=start
// [[10,11],[1,1]]\n2\n
// @lcpr case=end

 */

