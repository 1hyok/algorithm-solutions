// Problem: 구간 합 구하기
// URL: https://www.acmicpc.net/problem/2042

#include <iostream>
#include <vector>
#include <bit>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

struct SegTree
{
    vector<long long> tree;
    int n;

    explicit SegTree(const vector<long long>& arr)
    {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    void build(const vector<long long>& arr, const int node, const int start, const int end)
    {
        if (start == end)
        {
            tree[node] = arr[start];
            return;
        }
        const int mid = (start + end) / 2;
        build(arr, 2 * node, start, mid);
        build(arr, 2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void update(const int idx, const long long val)
    {
        update(1, 0, n - 1, idx, val);
    }

    void update(const int node, const int start, const int end, const int idx, const long long val)
    {
        if (start == end)
        {
            tree[node] = val;
            return;
        }
        const int mid = (start + end) / 2;
        if (idx <= mid)
        {
            update(2 * node, start, mid, idx, val);
        }
        else
        {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    long long query(const int l, const int r)
    {
        return query(1, 0, n - 1, l, r);
    }

    long long query(const int node, const int start, const int end, const int l, const int r)
    {
        if (start > r || end < l)
        {
            return 0;
        }

        if (l <= start && end <= r)
        {
            return tree[node];
        }
        const int mid = (start + end) / 2;
        return query(2 * node, start, mid, l, r) + query(2 * node + 1, mid + 1, end, l, r);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m, k;
    cin >> n >> m >> k;
    vector<long long> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    auto st = SegTree(arr);

    for (int i = 0; i < m + k; ++i)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            st.update(b - 1, c);
            continue;
        }
        cout << st.query(b - 1, c - 1) << '\n';
    }
}
