// Problem: 전역 임무
// URL: https://www.acmicpc.net/problem/30205

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
    long long p;
    cin >> n >> m >> p;
    while (n--)
    {
        vector<int> arr(m);
        int cnt = 0;
        for (int i = 0; i < m; ++i)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        for (const int sij : arr)
        {
            if (sij == -1)
            {
                cnt++;
                continue;
            }

            while (sij > p && cnt--)
            {
                p *= 2;
            }
            if (sij > p)
            {
                cout << 0;
                return 0;
            }
            p += sij;
        }
        while (cnt--)
        {
            p *= 2;
        }
    }
    cout << 1;
}
