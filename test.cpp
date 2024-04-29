#include <iostream>
using namespace std;
int main(){
    cout<<4%3<<endl;
    cout<<(-4)%3<<endl;
    cout<<(4)%(-3)<<endl;
    cout<<(-4)%(-3)<<endl;
}
// python是和除数保持一致的符号，c++是和被除数保持一致的符号
// >>> 4%3
// 1
// >>> (-4)%3
// 2
// >>> 4%(-3) 
// -2
// >>> (-4)%(-3) 
// -1
// a=(a/b)*b+a%b

// 1
// -1
// 1
// -1