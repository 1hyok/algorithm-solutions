// Problem: 숨바꼭질 3
// URL: https://www.acmicpc.net/problem/13549

#include <iostream>
#include <vector>
#include <bit>
#include <climits>
#include <algorithm>
#include <queue>

#define INF 100000

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector dist(INF + 1,INF + 1);
    dist[n] = 0;

    deque<int> dq;
    dq.push_back(n);
    while (!dq.empty())
    {
        const int t = dq.front();
        dq.pop_front();
        if (t == k)
        {
            cout << dist[t];
            break;
        }

        if (t + 1 <= INF && dist[t] + 1 < dist[t + 1])
        {
            dist[t + 1] = dist[t] + 1;
            dq.push_back(t + 1);
        }
        if (t - 1 >= 0 && dist[t] + 1 < dist[t - 1])
        {
            dist[t - 1] = dist[t] + 1;
            dq.push_back(t - 1);
        }
        if (2 * t <= INF && dist[t] < dist[2 * t])
        {
            dist[2 * t] = dist[t];
            dq.push_front(2 * t);
        }
    }
}
