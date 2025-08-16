// https://usaco.org/index.php?page=viewproblem2&cpid=968

#include <fstream>
#include <vector>
#include <stack>

using namespace std;

vector<int> graph[100001];
int component[100001];
char type[100001];

int main(void) {
    ifstream fin("milkvisits.in");
    int N, M;
    fin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        fin >> type[i];
    }

    for (int _ = 0; _ < N - 1; ++_) {
        int a, b;
        fin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int comp = 0;
    for (int i = 1; i <= N; ++i) {
        if (component[i]) continue;
        ++comp;

        stack<int> s;
        s.push(i);

        while (!s.empty()) {
            int c = s.top();
            s.pop();

            if (component[c] || type[c] != type[i]) continue;

            component[c] = comp;

            for (int n : graph[c]) {
                s.push(n);
            }
        }
    }

    ofstream fout("milkvisits.out");
    for (int q = 0; q < M; ++q) {
        int a, b;
        char t;
        fin >> a >> b >> t;

        if (component[a] == component[b] && t == type[a]) fout << 1;
        else if (component[a] != component[b]) fout << 1;
        else fout << 0;
    }
    fout << endl;
}