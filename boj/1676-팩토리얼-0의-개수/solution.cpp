// Problem: 팩토리얼 0의 개수
// URL: https://www.acmicpc.net/problem/1676

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

    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (i % 2 == 0)
        {
            cnt1++;
        }
        if (i % 5 == 0)
        {
            cnt2++;
        }
    }
    cout << min(cnt1, cnt2);
}
