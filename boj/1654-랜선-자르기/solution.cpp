// Problem: 랜선 자르기
// URL: https://www.acmicpc.net/problem/1654

#include <iostream>
#include <vector>
#include <bit>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, n;
    cin >> k >> n;

    vector<int> lan(k);
    for (int i = 0; i < k; ++i)
    {
        cin >> lan[i];
    }

    long long low = 1;
    int high = INT_MAX;
    int result = 0;
    while (low <= high)
    {
        const long long mid = high + (low - high) / 2;
        long long cnt = 0;
        for (int i = 0; i < k; ++i)
        {
            cnt += lan[i] / mid;
        }
        if (cnt < n)
        {
            high = mid - 1;
            continue;
        }
        result = mid;
        low = mid + 1;
    }
    cout << result;
}
