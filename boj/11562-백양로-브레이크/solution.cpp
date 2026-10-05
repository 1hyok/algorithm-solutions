// Problem: 백양로 브레이크
// URL: https://www.acmicpc.net/problem/11562

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

    vector matrix(n + 1, vector(n + 1, 1e9));
    for (int i = 1; i <= n; ++i)
    {
        matrix[i][i] = 0;
    }

    while (m--)
    {
        int u, v, b;
        cin >> u >> v >> b;
        matrix[u][v] = 0;
        matrix[v][u] = 1 - b;
    }
    int k;
    cin >> k;

    for (int l = 1; l <= n; ++l)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (matrix[i][l] + matrix[l][j] < matrix[i][j])
                {
                    matrix[i][j] = matrix[i][l] + matrix[l][j];
                }
            }
        }
    }

    while (k--)
    {
        int s, e;
        cin >> s >> e;
        cout << matrix[s][e] << '\n';
    }
}
