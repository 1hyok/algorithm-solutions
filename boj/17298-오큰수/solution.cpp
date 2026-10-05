// Problem: 오큰수
// URL: https://www.acmicpc.net/problem/17298

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
    vector<int> arr(n);
    vector<int> result(n);
    for (int i = 0; i < n; ++i)
    {
        int input;
        cin >> input;
        arr[i] = input;
    }

    stack<int> s;
    for (int i = n - 1; i >= 0; --i)
    {
        while (!s.empty() && arr[i] >= s.top())
        {
            s.pop();
        }
        if (s.empty())
        {
            result[i] = -1;
        }
        else
        {
            result[i] = s.top();
        }
        s.push(arr[i]);
    }
    for (const int& result1 : result)
    {
        cout << result1 << " ";
    }
}
