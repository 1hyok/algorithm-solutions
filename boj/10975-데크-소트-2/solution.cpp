// Problem: 데크 소트 2
// URL: https://www.acmicpc.net/problem/10975

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

    int n;
    cin >> n;
    vector<deque<int>> dq(n);
    int result = 0;
    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        for (int j = 0; j < n; ++j)
        {
            if (dq[j].empty())
            {
                result++;
                dq[j].push_back(num);
                break;
            }
            if (num >= dq[j].back())
            {
                dq[j].push_back(num);
                break;
            }
            if (num <= dq[j].front())
            {
                dq[j].push_front(num);
                break;
            }
        }
    }
    cout << result;
}
