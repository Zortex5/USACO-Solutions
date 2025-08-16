// https://usaco.org/index.php?page=viewproblem2&cpid=896

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comparator(pair<int, int> m1, pair<int, int> m2) {
    int m1x1 = m1.first - m1.second, m1x2 = m1.first + m1.second;
    int m2x1 = m2.first - m2.second, m2x2 = m2.first + m2.second;
    if (m1x1 == m2x1) return m1x2 > m2x2;
    return m1.first - m1.second < m2.first - m2.second;
}

int main() {
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);

    int n;
    cin >> n;

    vector<pair<int, int>> m;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        m.push_back({x, y});
    }
    sort(m.begin(), m.end(), comparator);

    int viewed = 0;
    int maxBaseX = 0;
    for (int i = 0; i < n; ++i) {
        pair<int, int> mountain = m[i];
        int mx = mountain.first, my = mountain.second;
        int baseX = mx + my;
        if (baseX > maxBaseX) ++viewed;
        maxBaseX = max(maxBaseX, baseX);
    }

    cout << viewed << "\n";
}