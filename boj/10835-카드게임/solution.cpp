// Problem: 카드게임
// URL: https://www.acmicpc.net/problem/10835

#include <iostream>
#include <vector>
#include <bit>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> left(n + 1);
    vector<int> right(n + 1);
    vector dp(n + 1, vector(n + 1, vector(3, -1)));

    for (int i = 1; i <= n; ++i)
        cin >> left[i];
    for (int i = 1; i <= n; ++i)
        cin >> right[i];

    dp[1][1][0] = 0;
    if (right[1] < left[1])dp[1][1][1] = right[1];
    dp[1][1][2] = 0;
    for (int i = 2; i <= n; ++i)
    {
        dp[i][1][0] = dp[i - 1][1][0];
        dp[i][1][2] = dp[i][1][0];

        if (dp[i][1][0] != -1 && right[1] < left[i])dp[i][1][1] = dp[i][1][0] + right[1];
    }

    for (int i = 2; i <= n; ++i)
    {
        dp[1][i][0] = dp[1][i - 1][1];
        dp[1][i][2] = dp[1][i][0];

        if (dp[1][i][0] != -1 && right[i] < left[1])dp[1][i][1] = dp[1][i][0] + right[i];
    }

    for (int i = 2; i <= n; ++i)
        for (int j = 2; j <= n; ++j)
        {
            dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j - 1][2]);

            if (j - 1 >= 1 && right[j - 1] < left[i])
                dp[i][j][0] = max(dp[i][j][0], dp[i][j - 1][1]);
            dp[i][j][2] = dp[i][j][0];

            if (right[j] < left[i])
            {
                if (dp[i - 1][j][0] != -1)dp[i][j][1] = dp[i - 1][j][0] + right[j];
                if (dp[i][j - 1][1] != -1)dp[i][j][1] = max(dp[i][j][1], dp[i][j - 1][1] + right[j]);
                if (dp[i - 1][j - 1][2] != -1)dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - 1][2] + right[j]);
            }
        }

    int result = 0;
    for (int i = 1; i <= n; ++i)
    {
        result = max(result, dp[i][n][2]);
        if (right[n] < left[i])result = max(result, dp[i][n][1]);
    }
    for (int i = 1; i <= n; ++i)
        result = max(max(result, dp[n][i][0]), dp[n][i][2]);
    cout << result;
}
