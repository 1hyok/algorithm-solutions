// Problem: 플로이드 2
// URL: https://www.acmicpc.net/problem/11780

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

    int n, m;
    cin >> n >> m;
    vector matrix(n + 1, vector<int>(n + 1, 1e9));
    for (int i = 1; i <= n; ++i)
    {
        matrix[i][i] = 0;
    }
    vector route(n + 1, vector<int>(n + 1));

    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        matrix[a][b] = min(matrix[a][b], c);
        route[a][b] = a;
    }

    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (i == j)
                {
                    continue;
                }
                if (matrix[i][k] + matrix[k][j] < matrix[i][j])
                {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                    route[i][j] = route[k][j];
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cout << (matrix[i][j] == 1e9 ? 0 : matrix[i][j]) << " ";
        }
        cout << '\n';
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (matrix[i][j] == 1e9 || i == j)
            {
                cout << 0 << '\n';
                continue;
            }
            int node = j;
            vector<int> stk;
            while (node)
            {
                // cout << "node:" << node << '\n';
                stk.push_back(node);
                node = route[i][node];
            }
            cout << stk.size() << ' ';
            for (int i = stk.size() - 1; i >= 0; --i)
            {
                cout << stk[i] << ' ';;
            }
            cout << '\n';
        }
    }
}
