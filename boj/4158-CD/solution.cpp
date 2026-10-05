// Problem: CD
// URL: https://www.acmicpc.net/problem/4158

#include <iostream>
#include <vector>
#include <bit>
#include <climits>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true)
    {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0)
        {
            break;
        }
        int cnt = 0;
        unordered_map<int, bool> um;
        for (int i = 0; i < n; ++i)
        {
            int input;
            cin >> input;
            um[input] = true;
        }
        for (int i = 0; i < m; ++i)
        {
            int input;
            cin >> input;
            if (um[input])
            {
                cnt++;
            }
        }
        cout << cnt<<'\n';
    }
}
