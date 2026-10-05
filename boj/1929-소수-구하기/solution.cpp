// Problem: 소수 구하기
// URL: https://www.acmicpc.net/problem/1929

#include <iostream>
#include <vector>
#include <bit>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    vector prime(n + 1, true);
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i * i <= n; ++i)
    {
        if (!prime[i])
        {
            continue;
        }
        for (long long k = static_cast<long long>(i) * i; k <= n; k += i)
        {
            prime[k] = false;
        }
    }

    for (int i = m; i <= n; ++i)
    {
        if (!prime[i])
        {
            continue;
        }
        cout << i << '\n';
    }
}
