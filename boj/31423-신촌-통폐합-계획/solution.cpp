// Problem: 신촌 통폐합 계획
// URL: https://www.acmicpc.net/problem/31423

#include <iostream>
#include <vector>
#include <bit>
#include <climits>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

vector<bool> visit;
vector<string> names;
vector<vector<int>> graph;

void dfs(const int u)
{
    cout << names[u];
    visit[u] = true;
    for (const auto v : graph[u])
    {
        if (visit[v])
        {
            continue;
        }
        dfs(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    visit.resize(n + 1);
    names.resize(n + 1);
    graph.resize(n + 1, vector<int>());
    for (int i = 1; i <= n; ++i)
    {
        cin >> names[i];
    }

    int s = 1;
    for (int k = 0; k < n - 1; ++k)
    {
        int i, j;
        cin >> i >> j;
        graph[i].push_back(j);
        s = i;
    }
    dfs(s);
}
