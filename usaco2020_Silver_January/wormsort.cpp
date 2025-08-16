// https://usaco.org/index.php?page=viewproblem2&cpid=992

#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>

using std::ifstream, std::ofstream, std::vector, std::pair, std::endl, std::sort, std::stack;

pair<int, pair<int, int>> wormholes[100001]; // array of wormholes sorted by width
int order[100001]; // original order of cows
int n, m;

bool canSort(int index) {
    vector<int> adjList[n + 1];
    for (int w = index; w <= m; ++w) {
        adjList[wormholes[w].second.first].push_back(wormholes[w].second.second);
        adjList[wormholes[w].second.second].push_back(wormholes[w].second.first);
    }

    int component = 1, components[n + 1] = {};

    for (int i = 1; i <= n; ++i) {
        if (!components[i]) {
            stack<int> s;
            s.push(i);
            components[i] = component;

            while (!s.empty()) {
                int c = s.top();
                s.pop();
                
                for (int d : adjList[c]) {
                    if (!components[d]) {
                        s.push(d);
                        components[d] = component;
                    }
                }
            }

            ++component;
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (components[i] != components[order[i]]) return false;
    }
    return true;
}


int main() {
    ofstream fout("wormsort.out");
    ifstream fin("wormsort.in");
    fin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        fin >> order[i];
    }

    for (int i = 1; i <= m; ++i) {
        int a, b, w;
        fin >> a >> b >> w;
        wormholes[i] = {w, {a, b}};
    }
    
    int matches = 0;
    for (int i = 1; i <= n; ++i) {
        if (order[i] == i) ++matches;
    }
    if (matches == n) {
        fout << -1 << endl;
        return 0;
    }

    sort(wormholes + 1, wormholes + m + 1);

    int lo = 1, hi = m, mid;
    while (lo < hi) {
        mid = (lo + hi + 1) / 2;
        if (canSort(mid)) {
            lo = mid;
        }
        else {
            hi = mid - 1;
        }
    }

    fout << wormholes[lo].first << endl;
}