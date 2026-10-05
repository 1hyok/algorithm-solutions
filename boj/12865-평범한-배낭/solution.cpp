// Problem: 평범한 배낭
// URL: https://www.acmicpc.net/problem/12865

#include <algorithm>
#include <iostream>
#include <vector>
#include <bit>
#include <climits>

#define MAX_WEIGHT 100000

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int k;
    cin >> n >> k;

    vector<int> weight(n + 1);
    vector<int> value(n + 1);
    for (int i = 1; i < n + 1; ++i)
    {
        cin >> weight[i] >> value[i];
    }

    vector dp(n + 1, vector<int>(k + 1));
    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 0; j < k + 1; ++j)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - weight[i] >= 0)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }

    // cout << *max_element(dp[n].begin(), dp[n].end());
    cout << dp[n][k];
}
