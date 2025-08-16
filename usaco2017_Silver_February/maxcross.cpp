// https://usaco.org/index.php?page=viewproblem2&cpid=715

#include <bits/stdc++.h>

using std::cin, std::cout;

int blights[100001];
int bsum[100001];

int main() {
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);

    int n, k, b;
    cin >> n >> k >> b;

    int light;
    for (int i = 0; i < b; ++i) {
        cin >> light;
        blights[light] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        bsum[i] = bsum[i - 1] + blights[i];
    }

    int min = k;
    for (int i = 0; i <= n - k; ++i) {
        min = std::min(min, bsum[i + k] - bsum[i]);
    }
    cout << min;
}