// Problem: 가장 긴 증가하는 부분 수열 2
// URL: https://www.acmicpc.net/problem/12015

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    long long n;
    cin >> n;
    vector<long long> a(n + 1);
    vector<long long> dp(n + 1);
    for (long long i = 1; i < n + 1; i++)
    {
        cin >> a[i];
    }


    for (long long i = 1; i < n + 1; i++)
    {
        dp[i] = 1;
        for (long long j = 1; j < i; j++)
        {
            if (a[i] > a[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << '\n';

    return 0;
}
