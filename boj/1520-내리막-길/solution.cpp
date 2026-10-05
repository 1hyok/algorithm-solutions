// Problem: 내리막 길
// URL: https://www.acmicpc.net/problem/1520

#include <iostream>
#include <vector>
#include <bit>
#include <climits>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

constexpr int dx[4] = {-1, 1, 0, 0};
constexpr int dy[4] = {0, 0, -1, 1};

int m, n, cnt = 0;
vector<vector<int>> _map;
vector<vector<bool>> visit;

void dfs(const int x, const int y)
{
    if (x == m - 1 && y == n - 1)
    {
        cnt++;
        return;
    }
    visit[x][y] = true;
    for (int i = 0; i < 4; ++i)
    {
        const int nx = x + dx[i];
        const int ny = y + dy[i];
        if (nx < 0 || nx > m - 1 || ny < 0 || ny > n - 1 || visit[nx][ny] || _map[nx][ny] >= _map[x][y])
        {
            continue;
        }
        dfs(nx, ny);
    }
    visit[x][y] = false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n;

    _map.resize(m, vector<int>(n));
    visit.resize(m, vector<bool>(n));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> _map[i][j];
        }
    }
    dfs(0, 0);

    cout << cnt;
}
