#include <iostream>
#include <vector>

const int MAX_SIZE = 100'001;

int color;

std::vector<std::vector<int>> g(MAX_SIZE);
std::vector<int> used(MAX_SIZE);
std::vector<std::vector<int>> res(1);

void dfs(int v) {
    used[v] = color;
    res[color].push_back(v);
    for (int i : g[v]) {
        if (!used[i]) {
            dfs(i);
        }
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            ++color;
            res.push_back(std::vector<int>(0));
            dfs(i);
        }
    }
    std::cout << color << '\n';
    for (int i = 1; i <= color; ++i) {
        std::cout << res[i].size() << '\n';
        for (int j : res[i]) {
            std::cout << j << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}
