// Problem: 도키도키 간식드리미
// URL: https://www.acmicpc.net/problem/12789

#include <iostream>
#include <vector>
#include <bit>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int order = 1;
    vector<int> stk;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        stk.push_back(num);

        while (stk.size() > 0 && stk.back() == order)
        {
            stk.pop_back();
            order++;
        }
    }

    cout << (order == n + 1 ? "Nice" : "Sad");
}
