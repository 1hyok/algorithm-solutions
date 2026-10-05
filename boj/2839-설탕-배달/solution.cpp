// Problem: 설탕 배달
// URL: https://www.acmicpc.net/problem/2839

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
    vector dp(n + 1, 1e9);

    dp[0] = 0;
    dp[3] = 1;
    for (int i = 5; i <= n; ++i)
    {
        dp[i] = min(dp[i], dp[i - 5] + 1);
        dp[i] = min(dp[i], dp[i - 3] + 1);
    }

    cout << (dp[n] == 1e9 ? -1 : dp[n]);
}
