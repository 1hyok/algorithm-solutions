// Problem: 토마토
// URL: https://www.acmicpc.net/problem/7576

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

    int m, n;
    cin >> m >> n;
    vector map(n, vector<int>(m));
    vector visit(n, vector(m, -1));
    queue<pair<int, int>> q;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> map[i][j];
            if (map[i][j] == 1)
            {
                visit[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    while (!q.empty())
    {
        const auto [x,y] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            constexpr int dx[4] = {-1, 1, 0, 0};
            constexpr int dy[4] = {0, 0, -1, 1};
            const int nx = x + dx[i];
            const int ny = y + dy[i];
            if (nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1 || map[nx][ny] == -1)
            {
                continue;
            }
            if (visit[nx][ny] == -1)
            {
                visit[nx][ny] = visit[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    int result = -1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (map[i][j] == 0 && visit[i][j] == -1)
            {
                cout << -1;
                return 0;
            }
            result = max(result, visit[i][j]);
        }
    }

    cout << result;
}
