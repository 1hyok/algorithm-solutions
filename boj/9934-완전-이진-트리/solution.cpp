// Problem: 완전 이진 트리
// URL: https://www.acmicpc.net/problem/9934

#include <iostream>
#include <vector>
#include <bit>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> arr;
vector<vector<int>> tree;
int k;

void go(const int left_most, const int depth)
{
    if (depth > k)
    {
        return;
    }
    const int root_idx = left_most + (1 << (k - depth)) - 1;
    if (root_idx < 0 || root_idx >= arr.size())
    {
        return;
    }
    // cout << "left_most:" << left_most << " root_idx:" << root_idx << " arr[root_idx]:" << arr[root_idx] << '\n';
    tree[depth].push_back(arr[root_idx]);
    go(left_most, depth + 1);
    go(root_idx + 1, depth + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k;
    tree.resize(k + 1);
    int node;
    while (cin >> node)
    {
        arr.push_back(node);
    }
    go(0, 1);

    for (int i = 1; i <= k; i++)
    {
        for (const int tree1 : tree[i])
        {
            cout << tree1 << " ";
        }
        cout << '\n';
    }
}
