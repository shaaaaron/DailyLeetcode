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
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2){
     const int PRIME=1000*1000*1000+7;
     int n=nums.size();
     
     long long min_v=*min_element(nums.begin(), nums.end());
     //int sum=accumulate(nums.begin(),nums.end(),0);   
     long long sum=0;
     for(auto num:nums) sum+=num;
     long long target=*max_element(nums.begin(), nums.end());
     long long ans=LONG_LONG_MAX; // 特殊处理最大
     
     if(2*cost1<=cost2){
         return (n*target-sum)*cost1%PRIME;
     }
     if(n==1) return 0;
     if(n==2){
         return (target-min_v)*cost1%PRIME;// 必须特殊处理，否则后面无法reduant退出
     }
     
     int reduant=0;
     while(true){
         long long tmp=0;
         
         long long s=target-min_v;
         long long d=n*target-sum-s;// 其他的差距
         //cout<<s<<","<<d<<endl;
         if(s>=d){
             tmp=d*cost2+(s-d)*cost1;
             //tmp%=PRIME;
         }else{
             if((s+d)%2) tmp+=cost1;
             tmp+=(s+d)/2*cost2;
             reduant++;
         }
         ans=min(ans, tmp); // 正确吗.。是取模后的最小值，还是最小值再取模？当前的方法会longlong越界吗？ 看看其他方法
         
         target++;
         //reduant++;
         if(reduant>=2) break;
     }
     
     return ans%PRIME;
     
    }
};