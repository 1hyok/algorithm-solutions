// Problem: 파이프 옮기기 2
// URL: https://www.acmicpc.net/problem/17069

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
    vector grid(n + 1, vector(n + 1, 1));
    vector dp(n + 1, vector(n + 1, vector<long long>(3)));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> grid[i][j];
        }
    }
    dp[1][2][0] = 1;
    for (int row = 1; row <= n; ++row)
    {
        for (int col = 3; col <= n; ++col)
        {
            if (grid[row][col] == 1)
            {
                continue;
            }
            if (grid[row][col - 1] == 0)
            {
                dp[row][col][0] = dp[row][col - 1][0] + dp[row][col - 1][2];
            }
            if (grid[row - 1][col] == 0)
            {
                dp[row][col][1] = dp[row - 1][col][1] + dp[row - 1][col][2];
            }
            if (grid[row - 1][col - 1] == 0 && grid[row - 1][col] == 0 && grid[row][col - 1] == 0)
            {
                dp[row][col][2] = dp[row - 1][col - 1][0] + dp[row - 1][col - 1][1] + dp[row - 1][col - 1][2];
            }
        }
    }
    cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
}
