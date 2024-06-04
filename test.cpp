#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <functional>
#include <ctime>
#include <cstdlib>
#include <iterator>
#include <sstream>

using namespace std;

// 引入两份代码的函数声明
void solution1(int t, vector<tuple<int, int, int, vector<int>, vector<int>>> &test_cases);
void solution2(int t, vector<tuple<int, int, int, vector<int>, vector<int>>> &test_cases);

void generate_test_case(vector<tuple<int, int, int, vector<int>, vector<int>>> &test_cases) {
    // 随机生成测试数据
    int t = 10; // 测试次数
    test_cases.clear();
    for (int i = 0; i < t; ++i) {
        int n = rand() % 100 + 1; // 数组大小 1 到 100
        int x = rand() % n;
        int y = x + rand() % (n - x);
        vector<int> a(n), b(n);
        for (int j = 0; j < n; ++j) {
            a[j] = rand() % 1000; // 数组元素值 0 到 999
            b[j] = rand() % 1000;
        }
        test_cases.push_back(make_tuple(n, x, y, a, b));
    }
}

// 用于存储输出结果的辅助函数
string capture_output(function<void()> func) {
    streambuf *oldCoutStreamBuf = cout.rdbuf();
    ostringstream strCout;
    cout.rdbuf(strCout.rdbuf());
    func();
    cout.rdbuf(oldCoutStreamBuf);
    return strCout.str();
}

vector<int> p(110);
int find(int x){
    if(p[x]==x)return x;
    return p[x]=find(p[x]);
}

void merge(int x, int y){
    p[find(x)]=find(y);
}

int main() {
    srand(time(0));

    // 生成测试数据
    vector<tuple<int, int, int, vector<int>, vector<int>>> test_cases;
    generate_test_case(test_cases);
    cout << "start" << endl;
    
    // 捕获两份代码的输出
    string output1 = capture_output([&]() { solution1(test_cases.size(), test_cases); });
    cout << "output1 end" << endl;
    string output2 = capture_output([&]() { solution2(test_cases.size(), test_cases); });
    cout << "output2 end" << endl;

    // 比较输出
    if (output1 == output2) {
        cout << "Outputs are the same." << endl;
    } else {
        cout << "Outputs are different." << endl;
        cout << "Output1: " << output1 << endl;
        cout << "Output2: " << output2 << endl;
    }

    return 0;
}

// 第一份代码实现
void solution1(int t, vector<tuple<int, int, int, vector<int>, vector<int>>> &test_cases) {
    cout<<"???";
    while (t--) {
        cout<<t<<endl;
        int n, x, y;
        vector<int> a, b;
        tie(n, x, y, a, b) = test_cases[t];
        iota(p.begin(), p.end(), 0);
        for (int i = x; i < y; i++) {
            merge(a[i], b[i]);
        }
        for (int i = 1; i <= n; i++) find(i);
        unordered_map<int, int> memo;
        unordered_set<int> seta, setb;
        for (int i = x; i < y; i++) {
            seta.insert(a[i]);
            setb.insert(b[i]);
            memo[p[a[i]]] ^= a[i];
            memo[p[b[i]]] ^= b[i];
        }
        int i = 0;
        while (i < n) {
            if (i == x) i = y;
            if (!seta.count(a[i]) && setb.count(a[i]))
                a[i] = memo[p[a[i]]] ^ a[i];
            i++;
        }
        i = 0;
        while (i < n) {
            if (i == x) i = y;
            if (seta.count(b[i]) && !setb.count(b[i]))
                b[i] = memo[p[b[i]]] ^ b[i];
            i++;
        }
        for (int i = x; i < y; i++) {
            swap(a[i], b[i]);
        }
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
        for (int i = 0; i < n; i++)
            cout << b[i] << " ";
        cout << endl;
    }
}

// 第二份代码实现
void pmx(vector<int> &v1, vector<int> &v2, int begin, int end) {
    int n = v1.size();
    unordered_map<int, unordered_set<int>> toEquiv;
    for (int i = begin; i < end; i++) {
        swap(v1[i], v2[i]);
        auto s = toEquiv[v1[i]];
        s.insert(toEquiv[v2[i]].begin(), toEquiv[v2[i]].end());
        s.insert(v1[i]);
        s.insert(v2[i]);
        for (int v : s) {
            toEquiv[v] = s;
        }
    }
    unordered_set<int> conflictSet;
    conflictSet.insert(v1.begin() + begin, v1.begin() + end);
    for (int i = 0; i < n; i++) {
        if (i >= begin && i < end) continue;
        if (!conflictSet.count(v1[i])) continue;
        for (auto newV : toEquiv[v1[i]]) {
            if (conflictSet.count(newV)) continue;
            v1[i] = newV;
            break;
        }
        conflictSet.insert(v1[i]);
    }
    conflictSet.clear();
    conflictSet.insert(v2.begin() + begin, v2.begin() + end);
    for (int i = 0; i < n; i++) {
        if (i >= begin && i < end) continue;
        for (auto newV : toEquiv[v2[i]]) {
            if (conflictSet.count(newV)) continue;
            v2[i] = newV;
            break;
        }
        conflictSet.insert(v2[i]);
    }
}

void solution2(int t, vector<tuple<int, int, int, vector<int>, vector<int>>> &test_cases) {
    while (t--) {
        int n, begin, end;
        vector<int> v1, v2;
        tie(n, begin, end, v1, v2) = test_cases[t];
        pmx(v1, v2, begin, end);
        copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
        copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
}
