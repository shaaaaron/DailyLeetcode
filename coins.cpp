#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> weights{3, 5, 2, 6, 11, 8};
    vector<double> values{0.01, 0.05, 0.10, 0.25, 0.50, 1.00};

    int M;
    while (cin >> M) {
        vector<int> coin_count(6);
        for (int i = 0; i < 6; i++) {
            cin >> coin_count[i];
        }

        vector<double> dp(M + 1, 0);  // 初始化dp数组，大小为M+1，初值为0

        // 处理每种硬币
        for (int i = 0; i < 6; i++) {
            int weight = weights[i];
            double value = values[i];
            int count = coin_count[i];

            // 使用二进制分解，优化多重背包
            for (int k = 1; count > 0; k *= 2) {
                int actual_num = min(k, count);
                int total_weight = actual_num * weight;
                double total_value = actual_num * value;
                for (int j = M; j >= total_weight; j--) {
                    dp[j] = max(dp[j], dp[j - total_weight] + total_value);
                }
                count -= actual_num;  // 减去已经使用的硬币数量
            }
        }

        // 输出结果，保留两位小数
        // cout << fixed << setprecision(2) << "$" << dp[M] << endl;
        printf("$%.2f\n", dp[M]);
    }

    return 0;
}
