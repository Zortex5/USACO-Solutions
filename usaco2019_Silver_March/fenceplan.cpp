// https://usaco.org/index.php?page=viewproblem2&cpid=944

#include <fstream>
#include <vector>
#include <stack>

using std::ifstream, std::ofstream, std::vector, std::pair, std::stack, std::min, std::max, std::endl;

vector<int> adjList[100000];
vector<pair<int, int>> coords(100000);

int main() {
    ifstream fin("fenceplan.in");
    int n, m;
    fin >> n >> m;

    for (int i = 0; i < n; ++i) {
        fin >> coords[i].first >> coords[i].second;
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        fin >> a >> b;
        adjList[--a].push_back(--b);
        adjList[b].push_back(a);
    }

    int minSemiperimeter = 200000000;
    bool visited[n] = {false};
    for (int i = 0; i < n; ++i) {
        if (visited[i]) continue;

        int minX = 100000000, minY = 100000000, maxX = 0, maxY = 0;
        stack<int> s;

        s.push(i);
        minX = min(minX, coords[i].first);
        maxX = max(maxX, coords[i].first);
        minY = min(minY, coords[i].second);
        maxY = max(maxY, coords[i].second);
        visited[i] = true;

        while (!s.empty()) {
            int c = s.top();
            s.pop();
            for (int d : adjList[c]) {
                if (!visited[d]) {
                    s.push(d);
                    minX = min(minX, coords[d].first);
                    maxX = max(maxX, coords[d].first);
                    minY = min(minY, coords[d].second);
                    maxY = max(maxY, coords[d].second);
                    visited[d] = true;
                }
            }
        }

        minSemiperimeter = min(minSemiperimeter, maxX - minX + maxY - minY);
    }

    ofstream fout("fenceplan.out");
    fout << minSemiperimeter * 2 << endl;
}