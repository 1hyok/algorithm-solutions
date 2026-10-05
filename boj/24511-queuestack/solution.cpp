// Problem: queuestack
// URL: https://www.acmicpc.net/problem/24511

#include <iostream>
#include <vector>
#include <bit>
#include <queue>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> is_stack(n);
    deque<int> d;
    for (int i = 0; i < n; ++i)
    {
        cin >> is_stack[i];
    }
    vector<int> elements(n);
    for (int i = 0; i < n; ++i)
    {
        int element;
        cin >> element;
        if (!is_stack[i])
        {
            d.push_back(element);
        }
    }

    int m;
    cin >> m;
    while (m--)
    {
        int element;
        cin >> element;
        d.push_front(element);
        cout << d.back()<<" ";
        d.pop_back();
    }
}
