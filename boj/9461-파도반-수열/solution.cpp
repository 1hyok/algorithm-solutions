// Problem: 파도반 수열
// URL: https://www.acmicpc.net/problem/9461

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

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> dp(n + 1);

        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; ++i)
        {
            dp[i] = dp[i - 2] + dp[i - 3];
        }

        cout << dp[n] << '\n';
    }
}
