// Problem: 물대기
// URL: https://www.acmicpc.net/problem/1368

#include <iostream>
#include <vector>
#include <bit>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;
vector<int> parent;
vector<int> _rank;

int find(const int x)
{
    if (parent[x] == x)
    {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void merge(const int x, const int y)
{
    const int root_x = find(x);
    const int root_y = find(y);
    if (_rank[root_x] > _rank[root_y])
    {
        parent[root_y] = root_x;
        return;
    }
    if (_rank[root_x] < _rank[root_y])
    {
        parent[root_x] = root_y;
        return;
    }

    parent[root_x] = root_y;
    _rank[root_y]++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    parent.resize(2 * n);
    for (int i = 0; i < 2 * n; ++i)
    {
        parent[i] = i;
    }

    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < n; ++i)
    {
        int w;
        cin >> w;
        edges.push_back({w, i, i + n});
        edges.push_back({w, i + n, i});
    }

    _rank.resize(2 * n);
    for (int i = n + 1; i < 2 * n; ++i)
    {
        merge(i, i - 1);
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int pij;
            cin >> pij;
            if (i == j)
            {
                continue;
            }
            edges.push_back({pij, i, j});
            edges.push_back({pij, j, i});
        }
    }
    sort(edges.begin(), edges.end());

    int result = 0;
    for (const auto& [w,u,v] : edges)
    {
        if (find(u) == find(v))
        {
            continue;
        }
        merge(u, v);
        result += w;
    }

    cout << result;
}
