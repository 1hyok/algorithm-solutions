// Problem: 회문
// URL: https://www.acmicpc.net/problem/17609

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
        string input;
        cin >> input;

        int i = 0, j = input.size() - 1, i2 = -1, j2 = -1, cnt = 0;
        while (i <= j)
        {
            if (input[i] != input[j])
            {
                if (++cnt == 2)
                {
                    break;
                }
                i2 = i + 1;
                j2 = j;
                j--;
                continue;
            }
            i++;
            j--;
        }

        if (cnt < 2)
        {
            cout << cnt << '\n';
            continue;
        }

        cnt = 1;
        while (i2 <= j2)
        {
            if (input[i2] != input[j2])
            {
                cnt++;
                cout << 2 << '\n';
                break;
            }
            i2++;
            j2--;
        }
        if (cnt == 1)
        {
            cout << 1 << '\n';
        }
    }
}
