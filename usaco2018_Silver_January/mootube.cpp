// https://usaco.org/index.php?page=viewproblem2&cpid=788

#include <fstream>
#include <vector>

using namespace std;

vector<pair<int, int>> graph[5001];

int check(int c, int p, int k) {
    int count = p != 0;

    for (pair<int, int> n : graph[c]) {
        if (n.first == p || n.second < k) continue;
        count += check(n.first, c, k);
    }

    return count;
}

int main(void) {
    ifstream fin("mootube.in");
    int N, Q;
    fin >> N >> Q;

    for (int _ = 0; _ < N - 1; ++_) {
        int p, q, r;
        fin >> p >> q >> r;
        graph[p].push_back({q, r});
        graph[q].push_back({p, r});
    }

    ofstream fout("mootube.out");
    for (int _ = 0; _ < Q; ++_) {
        int k, v;
        fin >> k >> v;

        fout << check(v, 0, k) << "\n";
    }
    fout << flush;
}