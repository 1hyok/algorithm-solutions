// Problem: 공유기 설치
// URL: https://www.acmicpc.net/problem/2110

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

    int n, c;
    cin >> n >> c;
    vector<int> house(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> house[i];
    }
    sort(house.begin(), house.end());

    int low = 1, high = 1e9;
    int max_min_interval = 0;
    while (low <= high)
    {
        const int mid = low + (high - low) / 2;
        int cnt = 1;
        int prev_idx = 0;
        for (int i = 1; i < n; ++i)
        {
            if (house[i] - house[prev_idx] >= mid)
            {
                prev_idx = i;
                cnt++;
            }
        }
        if (cnt < c)
        {
            high = mid - 1;
            continue;
        }
        max_min_interval = max(max_min_interval, mid);
        low = mid + 1;
    }

    cout << max_min_interval;
}
