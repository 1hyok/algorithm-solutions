// Problem: 크게 만들기
// URL: https://www.acmicpc.net/problem/2812

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

    int n, k;
    cin >> n >> k;
    string num;
    cin >> num;
    vector<char> stk;
    for (const char num1 : num)
    {
        while (!stk.empty() && stk.back() < num1 && k)
        {
            // cout << "k:" << k << '\n';
            // cout << "pop_back:" << stk.back() << '\n';
            stk.pop_back();
            k--;
        }
        // cout << "push_back:" << num1 << '\n';
        stk.push_back(num1);
    }
    while (k--)
    {
        stk.pop_back();
    }
    for (const char stk1 : stk)
    {
        cout << stk1;
    }
}
