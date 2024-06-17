#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <functional>   // function的头文件
using namespace std;

vector<int> p(110);
int find(int x){
    if(p[x]==x)return x;
    return p[x]=find(p[x]);
}

void merge(int x, int y){
    p[find(x)]=find(y);
}

int main(){
    int t;
    
    freopen("input.txt", "r", stdin);//NOTE:
    cin>>t;
    while(t){
        t--;
        int n,x,y;
        cin>>n>>x>>y;

        vector<int>a(n), b(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>b[i];
        iota(p.begin(), p.end(), 0);    // 用元素值而不是下标
        // p[0]=0;
        for(int i=x;i<y;i++){
            merge(a[i],b[i]);
        }

        for(int i=1;i<=n;i++) find(i);

        unordered_map<int,int> memo;
        unordered_set<int> seta, setb;
        for(int i=x;i<y;i++){
            seta.insert(a[i]);
            setb.insert(b[i]);
            memo[p[a[i]]]^=a[i];
            memo[p[b[i]]]^=b[i];
        }
        int i=0;
        while(i<n){
            if(i==x) i=y;
            if(i>=n) break;//NOTE:
            if(!seta.count(a[i]) && setb.count(a[i]))
                a[i]=memo[p[a[i]]]^a[i];
            i++;
        }
        i=0;
        while(i<n){
            if(i==x) i=y;
            if(i>=n) break;
            if(seta.count(b[i]) && !setb.count(b[i]))
                b[i]=memo[p[b[i]]]^b[i];
            i++;
        }

        for(int i=x;i<y;i++){
            swap(a[i], b[i]);
        }
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<endl;
        for(int i=0;i<n;i++)
            cout<<b[i]<<" ";
        cout<<endl;
    }
    return 0;
}