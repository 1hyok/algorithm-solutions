// Problem: 나무 자르기
// URL: https://www.acmicpc.net/problem/14247

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> H(n), A(n);
    for (int i = 0; i < n; i++) {
        cin >> H[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    vector<pair<int, int>> trees;
    for (int i = 0; i < n; i++) {
        trees.emplace_back(A[i], H[i]);
    }
    sort(trees.begin(), trees.end());

    long long total = 0;
    for (int day = 0; day < n; day++) {
        total += trees[day].second + static_cast<long long>(trees[day].first) * day;
    }

    cout << total << "\n";
    return 0;
}
