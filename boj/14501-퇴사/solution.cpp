// Problem: 퇴사
// URL: https://www.acmicpc.net/problem/14501

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
    vector<int> t(n + 1);
    vector<int> p(n + 1);
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> t[i] >> p[i];
        for (int j = 1; j <= i; ++j)
        {
            if (j + t[j] - 1 <= i)
            {
                dp[i] = max(dp[i], dp[j - 1] + p[j]);
            }
        }
    }

    cout << dp[n];
}
