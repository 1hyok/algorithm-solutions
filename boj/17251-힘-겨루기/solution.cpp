// Problem: 힘 겨루기
// URL: https://www.acmicpc.net/problem/17251

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
    vector<int> dp(n + 1);
    vector<int> dp2(n + 2);
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        if (arr[i] > dp[i - 1])
        {
            dp[i] = arr[i];
            continue;
        }
        dp[i] = dp[i - 1];
    }
    for (int i = 1; i <= n; ++i)
    {
        if (arr[n - i + 1] > dp2[i - 1])
        {
            dp2[i] = arr[n - i + 1];
            continue;
        }
        dp2[i] = dp2[i - 1];
    }

    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n - 1; ++i)
    {
        // cout << "dp:" << dp[i] << " dp2:" << dp2[n - i] << '\n';
        if (dp[i] > dp2[n - i])
        {
            cnt1++;
        }
        else if (dp[i] < dp2[n - i])
        {
            cnt2++;
        }
    }
    if (cnt1 > cnt2)
    {
        cout << "R";
    }
    else if (cnt1 == cnt2)
    {
        cout << "X";
    }
    else
    {
        cout << "B";
    }
    // cout << (cnt > n - 1 - cnt ? "R" : "B");
}
