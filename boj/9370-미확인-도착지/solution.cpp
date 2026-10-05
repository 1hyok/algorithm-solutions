// Problem: 미확인 도착지
// URL: https://www.acmicpc.net/problem/9370

#include <iostream>
#include <vector>
#include <bit>
#include <climits>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

void djikstra(vector<int>& dist, const vector<vector<pair<int, int>>>& graph, const int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    while (!pq.empty())
    {
        const auto [weight,curr] = pq.top();
        pq.pop();

        if (weight > dist[curr])
        {
            continue;
        }

        for (const auto& [w,next] : graph[curr])
        {
            if (dist[curr] + w >= dist[next])
            {
                continue;
            }
            dist[next] = dist[curr] + w;
            pq.push({dist[next], next});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int n, m, t;
        cin >> n >> m >> t;

        int s, g, h;
        cin >> s >> g >> h;


        int gh_w = 0;
        vector graph(n + 1, vector<pair<int, int>>());
        while (m--)
        {
            int a, b, d;
            cin >> a >> b >> d;
            graph[a].push_back({d, b});
            graph[b].push_back({d, a});
            if ((a == g && b == h) || (a == h && b == g))
            {
                gh_w = d;
            }
        }


        vector<int> dist_s(n + 1, 1e9);
        vector<int> dist_g(n + 1, 1e9);
        vector<int> dist_h(n + 1, 1e9);
        dist_s[s] = 0;
        djikstra(dist_s, graph, s);
        dist_g[g] = 0;
        djikstra(dist_g, graph, g);
        dist_h[h] = 0;
        djikstra(dist_h, graph, h);

        vector<bool> result(n + 1);
        for (int i = 0; i < t; ++i)
        {
            int dest;
            cin >> dest;

            if ((dist_s[g] + gh_w + dist_h[dest] == dist_s[dest]) || (dist_h[s] + gh_w + dist_g[dest] == dist_s[dest]))
            {
                result[dest] = true;
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            if (!result[i])
            {
                continue;
            }
            cout << i << " ";
        }
        cout << '\n';
    }
}
