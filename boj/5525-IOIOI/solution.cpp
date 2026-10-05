// Problem: IOIOI
// URL: https://www.acmicpc.net/problem/5525

#include <iostream>
#include <vector>
#include <bit>
#include <climits>


using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    string s;
    cin >> n >> m >> s;

    vector<int> dp(m);
    for (int i = 2; i < m; ++i)
    {
        dp[i] = dp[i - 1];
        if (s[i] == 'I' && s[i - 1] == 'O' && s[i - 2] == 'I')
        {
            dp[i]++;
        }
        // cout << "dp[" << i << "]:" << dp[i] << " ";
    }

    int cnt = 0;
    for (int i = 2 * n; i < m; ++i)
    {
        if (s[i] == 'I' && s[i - (2 * n)] == 'I' && dp[i] - dp[i - (2 * n)] == n)
        {
            cnt++;
        }
    }

    cout << cnt;
}
