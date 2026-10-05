// Problem: 제로
// URL: https://www.acmicpc.net/problem/10773

#include <iostream>
#include <vector>
#include <bit>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;
    stack<long long> s;
    long long sum = 0;
    while (k--)
    {
        long long input;
        cin >> input;
        if (input == 0)
        {
            sum -= s.top();
            s.pop();
            continue;
        }
        s.push((input));
        sum += input;
    }

    cout << sum;
}
