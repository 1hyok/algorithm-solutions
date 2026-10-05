// Problem: 트리 순회
// URL: https://www.acmicpc.net/problem/1991

#include <iostream>
#include <vector>
#include <bit>
#include <climits>


using namespace std;

vector<pair<char, char>> arr;

void preorder(const char node)
{
    if (node == '.')
    {
        return;
    }
    cout << node;
    preorder(arr[node].first);
    preorder(arr[node].second);
}

void inorder(const char node)
{
    if (node == '.')
    {
        return;
    }
    inorder(arr[node].first);
    cout << node;
    inorder(arr[node].second);
}

void postorder(const char node)
{
    if (node == '.')
    {
        return;
    }
    postorder(arr[node].first);
    postorder(arr[node].second);
    cout << node;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    arr.resize(n + 'A');
    while (n--)
    {
        char node, c1, c2;
        cin >> node >> c1 >> c2;
        arr[node].first = c1;
        arr[node].second = c2;
    }

    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
    cout << '\n';
}
