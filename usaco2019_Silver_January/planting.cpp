// https://usaco.org/index.php?page=viewproblem2&cpid=894

#include <fstream>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5;

int degrees[MAX_N + 1];

int main(void) {
    ifstream fin("planting.in");
    int N;
    fin >> N;

    int maxDegree = 0;
    for (int i = 1; i < N; ++i) {
        int a, b;
        fin >> a >> b;

        ++degrees[a];
        maxDegree = max(maxDegree, degrees[a]);

        ++degrees[b];
        maxDegree = max(maxDegree, degrees[b]);
    }

    ofstream fout("planting.out");
    fout << maxDegree + 1 << endl;
}