#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <cmath>
using namespace std;
// Description
//  有编号0到N-1的N个城市，问从0号城市出发，遍历完所有的城市并最后停留在N-1号城市的最短路径长度。
typedef pair<double, double> PDD;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
   while (T--) {
        int n;
        cin >> n;
        vector<PDD> city(n);
        for (int i = 0; i < n; i++)
            cin >> city[i].first >> city[i].second;

        vector<vector<double>> dp(1 << n, vector<double>(n, numeric_limits<double>::max()));
        dp[1][0] = 0; // 从城市0出发，只有城市0在路径中

        for (int mask = 1; mask < (1 << n); mask++) {
            for (int i = 0; i < n; i++) {
                if (!(mask & (1 << i))) continue; // 目标城市i
                for (int j = 0; j < n; j++) {
                    if (i == j || !(mask & (1 << j))) continue; // 出发城市j
                    int prev_mask = mask ^ (1 << i);
                    double dist = sqrt(pow(city[i].first - city[j].first, 2) + pow(city[i].second - city[j].second, 2));
                    dp[mask][i] = min(dp[mask][i], dp[prev_mask][j] + dist);
                }
            }
        }
        double min_path = dp[(1 << n) - 1][n-1];

        printf("%.2f\n", min_path);
    }

    return 0;
}
