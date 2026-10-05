// Problem: 신나는 함수 실행
// URL: https://www.acmicpc.net/problem/9184

#include <iostream>
#include <vector>
#include <bit>
#include <climits>
#include <algorithm>

using namespace std;

vector dp(21, vector(21, vector<int>(21)));

int w(const int a, const int b, const int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return 1;
    }
    if (a > 20 || b > 20 || c > 20)
    {
        return w(20, 20, 20);
    }
    if (dp[a][b][c])
    {
        return dp[a][b][c];
    }
    if (a < b && b < c)
    {
        return dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    }
    return dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
        {
            break;
        }
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
    }
}
