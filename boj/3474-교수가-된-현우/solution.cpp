// Problem: 교수가 된 현우
// URL: https://www.acmicpc.net/problem/3474

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

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int cnt1 = 0;
        for (int i = 2; i <= n; i *= 2)
        {
            cnt1 += n / i;
        }
        int cnt2 = 0;
        for (int i = 5; i <= n; i *= 5)
        {
            cnt2 += n / i;
        }
        cout << min(cnt1, cnt2) << '\n';
    }
}
