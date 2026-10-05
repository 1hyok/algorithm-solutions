// Problem: 1로 만들기 2
// URL: https://www.acmicpc.net/problem/12852

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

    int n;
    cin >> n;
    vector<int> route(n + 1);
    vector visit(n + 1, -1);

    queue<int> q;
    q.push(n);
    visit[n] = 0;
    while (!q.empty())
    {
        const auto curr = q.front();
        q.pop();

        if (curr % 3 == 0 && visit[curr / 3] == -1)
        {
            visit[curr / 3] = visit[curr] + 1;
            route[curr / 3] = curr;
            q.push(curr / 3);
        }
        if (curr % 2 == 0 && visit[curr / 2] == -1)
        {
            visit[curr / 2] = visit[curr] + 1;
            route[curr / 2] = curr;
            q.push(curr / 2);
        }
        if (curr - 1 >= 1 && visit[curr - 1] == -1)
        {
            visit[curr - 1] = visit[curr] + 1;
            route[curr - 1] = curr;
            q.push(curr - 1);
        }
    }

    cout << visit[1] << '\n';

    vector<int> stk;
    int node = 1;
    while (node)
    {
        stk.push_back(node);
        node = route[node];
    }
    for (int i = stk.size() - 1; i >= 0; --i)
    {
        cout << stk[i] << " ";
    }
}
