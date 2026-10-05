// Problem: 두 수의 합
// URL: https://www.acmicpc.net/problem/3273

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
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    int x, cnt = 0;
    cin >> x;
    vector<bool> check(x);
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] < x)
        {
            if (check[x - arr[i]])
            {
                cnt++;
            }
            check[arr[i]] = true;
        }
    }

    cout << cnt;
}
