// https://usaco.org/index.php?page=viewproblem2&cpid=1062

#include <iostream>
#include <vector>

using namespace std;

int N, days;
vector<int> graph[100001];

void dfs(int s, int p, vector<int> graph[100001]) {
    int roads = graph[s].size() - (s != 1);
    int cows = 1;
    while (cows < roads + 1) {
        ++days;
        cows <<= 1;
    }

    //cout << s << " HAS " << cows << " COWS AND " << roads << " ROADS\n";

    for (int c : graph[s]) {
        if (c == p) continue;

        ++days;
        dfs(c, s, graph);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    days = 0;

    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0, graph);

    cout << days << endl;
}