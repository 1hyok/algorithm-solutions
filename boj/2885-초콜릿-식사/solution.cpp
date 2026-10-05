// Problem: 초콜릿 식사
// URL: https://www.acmicpc.net/problem/2885

#include <iostream>
#include <vector>
#include <bit>
#include <limits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned int k;
    cin >> k;
    const int lsb = countr_zero(k);

    int total_bits = numeric_limits<unsigned int>::digits;
    const int msb = total_bits - 1 - countl_zero(k);

    if (msb == lsb)
    {
        cout << k << " " << 0;
        return 0;
    }

    cout << (1 << (msb + 1)) << " " << msb - lsb + 1;
}
