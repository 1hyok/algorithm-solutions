// Problem: RGB거리
// URL: https://www.acmicpc.net/problem/1149

#include <algorithm>
#include <iostream>
#include <vector>
#include <bit>
#include <climits>


using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector cost(n + 1, vector<int>(3));
    vector dp(n + 1, vector<int>(3));

    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cin >> cost[i][j];
        }
    }

    for (int i = 1; i < n + 1; ++i)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
    }

    cout << *min_element(dp[n].begin(), dp[n].end());
}
