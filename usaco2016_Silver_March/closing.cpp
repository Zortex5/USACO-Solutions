// https://usaco.org/index.php?page=viewproblem2&cpid=644

#include <vector>
#include <queue>
#include <fstream>

using std::vector, std::queue, std::ifstream, std::ofstream, std::endl;

vector<int> adjList[3003];
bool closed[3003];
int n, m;

bool check() {
    bool visited[3003] = {false};
    //std::cout << visited[3] << endl;
    //std::cout << "NEW" << endl;

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (!closed[i]) {
            visited[i] = true;
            q.push(i);
            break;
        }
    }

    while (!q.empty()) {
        int c = q.front();
        q.pop();
        //std::cout << "POPPED " << c << endl;

        for (int i : adjList[c]) {
            //std::cout << "CHECKING " << i << endl;
            //std::cout << visited[i] << " " << closed[c] << endl;
            if (visited[i] || closed[c]) continue;
            visited[i] = true;
            q.push(i);
            //std::cout << "PUSHED " << i << endl;
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (!visited[i] && !closed[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ifstream fin("closing.in");
    ofstream fout("closing.out");

    fin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a, b;
        fin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    if (check()) fout << "YES" << endl;
    else fout << "NO" << endl;

    for (int i = 0; i < n - 1; ++i) {
        int c;
        fin >> c;
        closed[c] = true;

        if (check()) fout << "YES" << endl;
        else fout << "NO" << endl;
    }
}