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
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int n=word.size();
        unordered_map<string,int> memo;
        for(int i=0;i<n;i+=k){
            memo[word.substr(i,k)]++;
        }
        
        int max_val=0;
        for(auto [_, num]:memo){
            max_val=max(max_val, num);
        }
        
        return n/k-max_val;
    }
};