// Problem: 개미굴
// URL: https://www.acmicpc.net/problem/14725

#include <iostream>
#include <vector>
#include <bit>
#include <climits>
#include <algorithm>
#include <map>
#include <queue>
#define ALPHABET 26

using namespace std;

typedef struct TrieNode
{
    map<string, TrieNode*> children;
} TrieNode;


void dfs(TrieNode* const& node, const int depth = 0)
{
    for (const auto& [str,child] : node->children)
    {
        for (int j = 0; j < depth; ++j)
        {
            cout << "--";
        }
        cout << str << '\n';
        dfs(child, depth + 1);
    }
}

void deleteTree(TrieNode* node)
{
    for (const auto& [str,child] : node->children)
    {
        deleteTree(child);
    }
    delete node;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    const auto& root = new TrieNode();

    while (n--)
    {
        int k;
        cin >> k;
        auto node = root;
        while (k--)
        {
            string input;
            cin >> input;

            if (node->children.find(input) == node->children.end())
            {
                node->children[input] = new TrieNode();
            }
            node = node->children[input];
        }
    }

    dfs(root);
    deleteTree(root);
}
