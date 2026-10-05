// Problem: 장난감 조립
// URL: https://www.acmicpc.net/problem/2637

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

    vector<vector<int>> graph(n + 1);
    vector<int> indegree(n + 1);
    vector lower_part_num(n + 1, vector<int>(n + 1));
    while (m--)
    {
        int x, y, k;
        cin >> x >> y >> k;
        graph[y].push_back(x);
        indegree[x]++;
        lower_part_num[x][y] = k;
    }

    queue<int> q;
    vector<int> base_part_set;
    for (int i = 1; i <= n; ++i)
    {
        if (indegree[i] == 0)
        {
            lower_part_num[i][i] = 1;
            base_part_set.push_back(i);
            q.push(i);
        }
    }
    sort(base_part_set.begin(), base_part_set.end());

    while (!q.empty())
    {
        const int curr = q.front();
        q.pop();

        for (const int next : graph[curr])
        {
            for (const int base_part : base_part_set)
            {
                if (curr == base_part)
                {
                    continue;
                }
                lower_part_num[next][base_part] += lower_part_num[next][curr] * lower_part_num[curr][base_part];
            }
            if (--indegree[next] == 0)
            {
                q.push(next);
            }
        }
    }

    for (const int base_part : base_part_set)
    {
        cout << base_part << " " << lower_part_num[n][base_part] << '\n';
    }
}
