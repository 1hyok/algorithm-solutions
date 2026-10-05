// Problem: 방벽 게임
// URL: https://www.acmicpc.net/problem/32714

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
    // vector dp(n + 1, vector<int>(2));
    //
    // for (int i = 1; i <= n; ++i)
    // {
    //     dp[i][0];
    // }
    if (n == 2)
    {
        cout << 1;
        return 0;
    }
    if (n == 3)
    {
        cout << 3;
        return 0;
    }
    cout << ((n - 2) * 2 + n);
}
