// Problem: 공약수
// URL: https://www.acmicpc.net/problem/2436

#include <iostream>
#include <vector>
#include <bit>

using namespace std;

long long get_gcd(const long long a, const long long b)
{
    return b == 0 ? a : get_gcd(b, a % b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long gcd, lcm;
    cin >> gcd >> lcm;
    const long long prod = gcd * lcm;
    long long result_x = gcd;
    long long result_y = lcm;

    //첫 번째 수가 최대공약수로 나누어 떨어지는가? -> 예
    for (long long tmp_x = gcd + gcd; tmp_x * tmp_x <= prod; tmp_x += gcd)
    {
        //최소공배수와 최대공약수의 곱이 첫 번째 수로 나누어 떨어지는가?
        if (prod % tmp_x != 0)continue;

        //두 수의 최대 공약수가 올바른가?
        const long long tmp_y = prod / tmp_x;
        const long long tmp_gcd = get_gcd(tmp_x, tmp_y);
        if (tmp_gcd != gcd)continue;

        if (tmp_x + tmp_y < result_x + result_y)
        {
            result_x = tmp_x;
            result_y = tmp_y;
        }
    }

    cout << result_x << " " << result_y;
}
