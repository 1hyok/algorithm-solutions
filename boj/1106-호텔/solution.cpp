// Problem: 호텔
// URL: https://www.acmicpc.net/problem/1106

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

    int c, n;
    cin >> c >> n;
    vector<int> weight(n + 1);
    vector<int> value(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> weight[i] >> value[i];
    }

    vector<int> dp(100001);
    int cost = 0, w = 1;
    while (cost < c)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (w < weight[i])
            {
                continue;
            }
            dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
            cost = max(cost, dp[w]);
        }
        w++;
    }

    cout << w - 1;
}
