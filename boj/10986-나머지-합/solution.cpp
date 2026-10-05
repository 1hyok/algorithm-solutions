// Problem: 나머지 합
// URL: https://www.acmicpc.net/problem/10986

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

    int n, m;
    cin >> n >> m;
    vector<long long> arr(n + 1);
    vector<int> mod(m);
    mod[0] = 1;

    for (int i = 1; i <= n; ++i)
    {
        int num;
        cin >> num;
        arr[i] = num + arr[i - 1];
        // cout << "arr[" << i << "]:" << arr[i] << '\n';
        mod[arr[i] % m]++;
    }
    // cout << '\n';

    long long result = 0;
    for (int i = 0; i < m; ++i)
    {
        // cout << "mod[" << i << "]:" << mod[i] << '\n';
        result += static_cast<long long>(mod[i]) * (mod[i] - 1) / 2;
    }

    cout << result;
}
