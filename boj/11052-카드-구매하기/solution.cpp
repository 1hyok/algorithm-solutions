// Problem: 카드 구매하기
// URL: https://www.acmicpc.net/problem/11052

#include <iostream>
#include <vector>
#include <bit>
#include <climits>


using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i < n + 1; ++i)
    {
        cin >> arr[i];
    }
    vector<int> dp(n + 1);
    for (int i = 1; i < n + 1; ++i)
    {
        dp[i] = arr[i];
        for (int j = 1; j < i; ++j)
        {
            dp[i] = max(dp[i], dp[j] + dp[i - j]);
        }
    }

    cout << dp[n];
}
