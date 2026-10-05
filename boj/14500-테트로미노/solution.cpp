// Problem: 테트로미노
// URL: https://www.acmicpc.net/problem/14500

#include <iostream>
#include <vector>
#include <bit>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

constexpr int dx[4] = {-1, 1, 0, 0};
constexpr int dy[4] = {0, 0, -1, 1};
vector<vector<int>> paper;
int n, m;
int max_sum = 0;

void dfs(vector<vector<bool>>& visit, const int depth, const int sum, const int x, const int y)
{
    if (depth == 4)
    {
        max_sum = max(max_sum, sum);
        return;
    }
    visit[x][y] = true;
    for (int direction = 0; direction < 4; ++direction)
    {
        const int next_x = x + dx[direction];
        const int next_y = y + dy[direction];
        if (next_x < 0 || next_x > n - 1 || next_y < 0 || next_y > m - 1)
        {
            continue;
        }
        if (!visit[next_x][next_y])
        {
            dfs(visit, depth + 1, sum + paper[next_x][next_y], next_x, next_y);
        }
    }
    visit[x][y] = false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    paper.resize(n, vector<int>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> paper[i][j];
        }
    }

    vector visit1(n, vector<bool>(m));
    for (int x = 0; x < n; ++x)
    {
        for (int y = 0; y < m; ++y)
        {
            // vector visit1(n, vector<bool>(m));
            dfs(visit1, 1, paper[x][y], x, y);

            int sum = paper[x][y];
            int cnt = 1, min_num = 1000;
            for (int direction = 0; direction < 4; ++direction)
            {
                const int next_x = x + dx[direction];
                const int next_y = y + dy[direction];
                if (next_x < 0 || next_x > n - 1 || next_y < 0 || next_y > m - 1)
                {
                    continue;
                }
                min_num = min(min_num, paper[next_x][next_y]);
                sum += paper[next_x][next_y];
                cnt++;
            }
            if (cnt == 5)
            {
                sum -= min_num;
            }
            max_sum = max(sum, max_sum);
        }
    }

    cout << max_sum;
}
