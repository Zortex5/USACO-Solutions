// https://usaco.org/index.php?page=viewproblem2&cpid=691

#include <bits/stdc++.h>

using namespace std;

const int MAX_GAMES = 100000;
int h[MAX_GAMES + 1], p[MAX_GAMES + 1], s[MAX_GAMES + 1];
int hs = 0, ps = 0, ss = 0;

int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    int n;
    cin >> n;

    char m;
    for (int i = 1; i <= n; ++i) {
        cin >> m;
        if (m == 'H') {
            ++hs;
        }
        else if (m == 'P') {
            ++ps;
        }
        else {
            ++ss;
        }
        h[i] = hs;
        p[i] = ps;
        s[i] = ss;
    }

    
    int maximum = 0;
    for (int i = 0; i < n; ++i) {
        int total;
        int sum1 = max(h[i], max(p[i], s[i]));
        int sum2 = max(h[n] - h[i], max(p[n] - p[i], s[n] - s[i]));
        total = sum1 + sum2;
        maximum = max(maximum, total);
    }
    cout << maximum << endl;
}