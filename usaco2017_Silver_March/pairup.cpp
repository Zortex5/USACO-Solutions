// https://usaco.org/index.php?page=viewproblem2&cpid=738

#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("pairup.in");
    ofstream fout("pairup.out");

    int n;
    fin >> n;

    vector<pair<int, int>> cows;

    for (int i = 0; i < n; ++i) {
        int a, b;
        fin >> a >> b;
        cows.push_back({b, a});
    }

    sort(cows.begin(), cows.end());

    int time = 0;
    int l = 0;
    int r = cows.size() - 1;
    while (l <= r) {
        time = max(time, cows[l].first + cows[r].first);

        if (cows[r].second > cows[l].second) {
            cows[r].second -= cows[l].second;
            ++l;
        }
        else if (cows[l].second > cows[r].second) {
            cows[l].second -= cows[r].second;
            --r;
        }
        else {
            if (l == r) break;
            ++l;
            --r;
        }
    }

    fout << time << "\n";
}