// Problem: 스티커
// URL: https://www.acmicpc.net/problem/9465

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

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector map(2, vector<int>(n + 1));
        vector dp(2, vector<int>(n + 1));
        for (int i = 0; i < 2; ++i)
        {
            for (int j = 1; j < n + 1; ++j)
            {
                cin >> map[i][j];
            }
        }
        dp[0][1] = map[0][1];
        dp[1][1] = map[1][1];

        int max_score = max(dp[0][1], dp[1][1]);
        for (int i = 2; i < n + 1; ++i)
        {
            dp[0][i] = max(dp[1][i - 1] + map[0][i], max(dp[1][i - 2] + map[0][i], dp[0][i - 2] + map[0][i]));
            dp[1][i] = max(dp[0][i - 1] + map[1][i], max(dp[0][i - 2] + map[1][i], dp[1][i - 2] + map[1][i]));
            max_score = max(dp[0][i], dp[1][i]);
        }

        cout << max_score << '\n';
    }
}
