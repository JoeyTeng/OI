// closingfarm
// Graph Theory, Union-find set, Offline algorithm

#include<bits/stdc++.h>

void unite(std::vector<int>& uf_set, int a, int b);
int find(std::vector<int>& uf_set, int n);

int main() {
    int N = 0;
    int M = 0;

    std::cin >> N >> M;

    std::vector<std::vector<int> > graph(N + 1);
    for (int i = 0; i < M; ++i) {
        int s = 0;
        int e = 0;
        std::cin >> s >> e;
        graph.at(s).push_back(e);
        graph.at(e).push_back(s);
    }

    std::istream_iterator<int> int_cin(std::cin);
    std::istream_iterator<int> int_end;
    std::vector<int> closing(int_cin, int_end);

    std::vector<int> uf_set;
    for (int i = 0; i <= N; ++i) {
        uf_set.push_back(i);
    }
    std::vector<int> used(N + 1, 0);
    int sets = 0;
    std::stack<int> ans;

    for (auto i = closing.rbegin(); i != closing.rend(); ++i) {
        used.at(*i) = 1;
        ++sets;
        for (auto j = graph.at(*i).begin(); j != graph.at(*i).end(); ++j) {
            if (used.at(*j) && (find(uf_set, *i) != find(uf_set, *j))) {
                --sets;
                unite(uf_set, *i, *j);
            }
        }
        if (sets == 1) {
            ans.push(1);
        } else {
            ans.push(0);
        }
    }
    for (int i = ans.top(); !ans.empty(); ans.pop(), i = ans.empty() || ans.top()) {
        if (i) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}

void unite(std::vector<int>& uf_set, int a, int b) {
    uf_set.at(find(uf_set, b)) = find(uf_set, a);
}

int find(std::vector<int>& uf_set, int n) {
    if (uf_set.at(n) != n) {
        uf_set.at(n) = find(uf_set, uf_set.at(n));
    }
    return uf_set.at(n);
}
