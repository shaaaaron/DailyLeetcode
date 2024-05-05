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
    bool isValid(string word) {
        if(word.size()<=2) return false;

        bool flag1=false, flag2=false;
        for(char x: word){
            if(x=='@' || x=='#' || x=='$')
                return false;
            if(x-'0'>=0 && x-'0'<=9) continue;
            if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u'||x=='A' || x=='E' || x=='I' || x=='O' || x=='U')
                flag1=true;
            else
                flag2=true;
        }
        
        return flag1&&flag2;
    }
};