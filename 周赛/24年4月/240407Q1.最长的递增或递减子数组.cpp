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

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxzeng=1; int maxjian=1;
        int nowzeng=1; int nowjian=1;
        for(int i=0;i<nums.size();i++){
            if(i!=0){
                if(nums[i-1]>nums[i]){
                    nowjian++;
                    nowzeng=1;
                }else if(nums[i-1]<nums[i]){
                    nowzeng++;
                    nowjian=1;
                }else{
                    nowzeng=1;
                    nowjian=1;
                }
                maxzeng=max(maxzeng, nowzeng);
                maxjian=max(maxjian, nowjian);
            }
        }
        
        return max(maxzeng,maxjian);
    }
};