/*
 * @lc app=leetcode.cn id=2007 lang=cpp
 * @lcpr version=30122
 *
 * [2007] 从双倍数组中还原原数组
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
// 我的思路是每次对于最小的，二分找到其两倍，多个相同则从左边开始找。
// 实际上也可以双指针，一次不只是一个，而是多个。 
    vector<int> findOriginalArray(vector<int>& a) {
        vector<int> ans;
        
        sort(a.begin(), a.end());
        int n=a.size();
        
        vector<int> visited(a.size(), false);
        for(int i=0;i<a.size();i++){
            if(visited[i]==true) continue;
            int l=i+1, r=a.size()-1;
            while(l<=r){
                int mid=(l+r)/2;
                if(a[mid]>2*a[i] || a[mid]==2*a[i]&&!visited[mid]){
                    r=mid-1;
                }else{
                    l=mid+1;    
                }
            }
            if(i+1<=l && l<n && a[l]==2*a[i] && visited[l]==false){
                visited[i]=true;
                visited[l]=true;
                ans.push_back(a[i]);
            }else{
                return vector<int>{};
            }
        }
        
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,4,2,6,8]\n
// @lcpr case=end

// @lcpr case=start
// [6,3,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

