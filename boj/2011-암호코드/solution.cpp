// Problem: 암호코드
// URL: https://www.acmicpc.net/problem/2011

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

    string input;
    cin >> input;

    vector<int> dp(input.size());
    if (input.size() == 1 || input[0] - '0' == 0)
    {
        cout << (input[0] - '0' == 0 ? 0 : 1);
        return 0;
    }

    dp[0] = 1; //0이 아닌 숫자는 한 자리 수로서 암호로서 기능
    const int num = (input[0] - '0') * 10 + input[1] - '0';
    dp[1] = 1;
    if (num >= 10 && num <= 26)
    {
        if (input[1] - '0' == 0)
        {
            dp[1] = 1;
        }
        else
        {
            dp[1] = 2;
        }
    }
    else if (input[1] - '0' == 0)
    {
        cout << 0;
        return 0;
    }

    for (int i = 2; i < input.size(); ++i)
    {
        if (input[i] - '0' == 0)
        {
            if (input[i - 1] - '0' != 1 && input[i - 1] - '0' != 2)
            {
                cout << 0;
                return 0;
            }
            dp[i] = dp[i - 2];
            continue;
        }

        dp[i] = dp[i - 1];
        if (((input[i - 1] - '0') != 1 && (input[i - 1] - '0') != 2) || ((input[i - 1] - '0') == 2 && input[i] - '0' >
            6))
        {
            continue;
        }

        dp[i] += dp[i - 2];
        dp[i] %= 1000000;

        // cout << "dp[" << i << "]:" << dp[i] << '\n';
    }

    cout << dp[input.size() - 1];
}
