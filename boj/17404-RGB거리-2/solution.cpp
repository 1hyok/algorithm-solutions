// Problem: RGB거리 2
// URL: https://www.acmicpc.net/problem/17404

#include <iostream>
#include <vector>
#include <bit>
#include <climits>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector cost(n + 1, vector<int>(3));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cin >> cost[i][j];
        }
    }

    int min_cost = 1e9;
    for (int i = 0; i < 3; ++i)
    {
        vector dp(n + 1, vector<int>(3));
        dp[1][i] = cost[1][i];
        dp[1][(i + 1) % 3] = 1e9;
        dp[1][(i + 2) % 3] = 1e9;
        for (int j = 2; j <= n; ++j)
        {
            dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + cost[j][0];
            dp[j][1] = min(dp[j - 1][0], dp[j - 1][2]) + cost[j][1];
            dp[j][2] = min(dp[j - 1][0], dp[j - 1][1]) + cost[j][2];
        }
        min_cost = min(min_cost, min(dp[n][(i + 1) % 3], dp[n][(i + 2) % 3]));
    }

    cout << min_cost;
}
