#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main() {
    
    freopen("input.txt", "r", stdin);
    
    int n, x, y;
    while (cin >> n) {

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        
        cin >> x >> y;
        y++;
        
        vector<int> ans(n);
        unordered_set<int> memo;
        for(int i=x;i<y;i++){
            ans[i]=a[i];
            memo.insert(a[i]);
        }
        int i=0;
        int j=0;
        while(i<n){
            if(i==x) i=y;
            if(i>=n) break;
            while(memo.count(b[j])){
                j++;
            }
            ans[i]=b[j];
            i++;
            j++;
        }
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << endl;


        memo.clear();
        for(int i=x;i<y;i++){
            ans[i]=b[i];
            memo.insert(b[i]);
        }
        i=0;
        j=0;
        while(i<n){
            if(i==x) i=y;
            if(i>=n) break;
            while(memo.count(a[j])){
                j++;
            }
            ans[i]=a[j];
            i++;
            j++;
        }

        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
