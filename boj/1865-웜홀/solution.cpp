// Problem: 웜홀
// URL: https://www.acmicpc.net/problem/1865

#include <iostream>
#include <vector>
#include <bit>
#include <climits>
#include <algorithm>

using namespace std;

void bf(const int n, const vector<tuple<int, int, int>>& edges)
{
    vector<int> dist(n + 1);
    for (int i = 0; i < n - 1; ++i)
    {
        for (const auto& [w,u,v] : edges)
        {
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (const auto& [w,u,v] : edges)
    {
        if (dist[u] + w < dist[v])
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m, w;
        cin >> n >> m >> w;
        vector<tuple<int, int, int>> edges;
        for (int i = 0; i < m; ++i)
        {
            int s, e, t;
            cin >> s >> e >> t;
            edges.emplace_back(t, s, e);
            edges.emplace_back(t, e, s);
        }

        for (int i = 0; i < w; ++i)
        {
            int s, e, t;
            cin >> s >> e >> t;
            edges.emplace_back(-t, s, e);
        }

        bf(n, edges);
    }
}
