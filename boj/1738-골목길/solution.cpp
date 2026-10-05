// Problem: 골목길
// URL: https://www.acmicpc.net/problem/1738

#include <iostream>
#include <vector>
#include <bit>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector dist(n + 1, -1e9);
    dist[1] = 0;
    vector<tuple<int, int, int>> edges(m);

    for (int i = 0; i < m; ++i)
    {
        int u, v, money;
        cin >> u >> v >> money;
        edges[i] = {money, u, v};
    }

    vector<int> route(n + 1);
    for (int i = 0; i < n - 1; ++i)
    {
        for (const auto& [m,u,v] : edges)
        {
            if (dist[u] > -1e9 && dist[u] + m > dist[v])
            {
                route[v] = u;
                dist[v] = dist[u] + m;
            }
        }
    }


    vector<bool> affected(n + 1);
    for (const auto& [m,u,v] : edges)
    {
        if (dist[u] > -1e9 && dist[u] + m > dist[v])
        {
            affected[v] = true;
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (const auto& [m,u,v] : edges)
        {
            if (affected[u])
            {
                affected[v] = true;
            }
        }
    }

    vector<int> result;
    int curr = n;
    while (curr)
    {
        if (affected[curr])
        {
            cout << -1;
            return 0;
        }
        result.push_back(curr);
        curr = route[curr];
    }

    for (int i = result.size() - 1; i >= 0; --i)
    {
        cout << result[i] << " ";
    }
}
