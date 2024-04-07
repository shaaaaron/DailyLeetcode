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
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        vector<int> left, right;
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int mid;
        if(n%2==1){
            n=n/2;
            for(int i=0;i<n;i++){
                left.push_back(nums[i]);
                right.push_back(nums[n+1 +i]);
            } 
            mid=nums[n];
        }else{
            n=n/2-1;
            for(int i=0;i<n;i++){
                left.push_back(nums[i]);
                right.push_back(nums[n+2 +i]);
            }
            left.push_back(nums[n]);
            mid=nums[n+1];
        }

        priority_queue<int, vector<int>> left_heap(left.begin(), left.end()); // 大顶
        priority_queue<int, vector<int>, greater<int>> right_heap(right.begin(), right.end()); // 小丁

        long long ans=0;//
        while(mid!=k){
            
            if(mid==k) return ans;
            else if (mid<k){
                ans+=k-mid; // 直接增加到k
                mid=k;
                right_heap.push(mid);
                mid=right_heap.top();
                right_heap.pop();
            }else{
                ans+=mid-k;
                mid=k;
                left_heap.push(mid);
                mid=left_heap.top();
                left_heap.pop();           
            }
            
            // cout<<left_heap.top()<<"< "<<mid<<"< "<<right_heap.top()<<"< "<<endl;
        }
        return ans;
    }
};