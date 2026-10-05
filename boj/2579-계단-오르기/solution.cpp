// Problem: 계단 오르기
// URL: https://www.acmicpc.net/problem/2579

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

    vector<int> stair(n + 1);

    for (int i = 1; i < n + 1; ++i)
    {
        cin >> stair[i];
    }

    vector dp(n + 1, vector<int>(2));

    dp[1][0] = stair[1];
    for (int i = 2; i < n + 1; ++i)
    {
        dp[i][1] = dp[i - 1][0] + stair[i];
        dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + stair[i];
    }

    cout << max(dp[n][1], dp[n][0]);
}
