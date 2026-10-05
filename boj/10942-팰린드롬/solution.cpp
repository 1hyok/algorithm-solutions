// Problem: 팰린드롬?
// URL: https://www.acmicpc.net/problem/10942

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
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    vector dp(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        dp[i][i] = 1;
    }
    for (int i = 1; i < n; ++i)
    {
        if (arr[i] == arr[i - 1])
        {
            dp[i - 1][i] = 1;
        }
    }

    for (int i = 0; i < n - 2; ++i)
    {
        for (int j = 1; j < n - i - 1; ++j)
        {
            if (dp[j][j + i] && arr[j - 1] == arr[j + i + 1])
            {
                dp[j - 1][j + i + 1] = 1;
            }
        }
    }

    int m;
    cin >> m;
    while (m--)
    {
        int s, e;
        cin >> s >> e;
        cout << dp[s - 1][e - 1] << '\n';
    }
}
