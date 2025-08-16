// https://usaco.org/index.php?page=viewproblem2&cpid=895

#include <bits/stdc++.h>

using namespace std;

int n;
const int MAX_N = 1000;
bool visited[MAX_N][MAX_N];
char grid[MAX_N][MAX_N];
int r_changes[] = {-1, 0, 0, 1};
int c_changes[] = {0, -1, 1, 0};


pair<int, int> operator+(pair<int, int>& f, pair<int, int>& s) {
    return {f.first + s.first, f.second + s.second};
}


pair<int, int> flood(int r, int c) {
    if (visited[r][c]) {
        return {0, 0};
    }
    visited[r][c] = true;

    if (grid[r][c] == '.') return {0, 0};
    
    pair<int, int> ap = {1, 0};

    for (int i = 0; i < 4; ++i) {
        int nr = r + r_changes[i];
        int nc = c + c_changes[i];

        if (nr == -1 || nr == n) {
            ++ap.second;
            if (nc == -1 || nc == n) {
                ++ap.second;
                continue;
            }
            continue;
        }
        else if (nc == -1 || nc == n) {
            ++ap.second;
            continue;
        }
        else if (grid[nr][nc] == '.') {
            ++ap.second;
        }

        pair<int, int> nap = flood(nr, nc);
        ap = ap + nap;
    }

    return ap;
}


int main() {
    ifstream fin("perimeter.in");
    ofstream fout("perimeter.out");

    fin >> n;
    if (n == 1) {
        fout << "1 4" << endl;
        return 0;
    }

    for (int i = 0; i < n; ++i) {    // CREATE GRID
        for (int j = 0; j < n; ++j) {
            fin >> grid[i][j];
        }
    }

    pair<int, int> blobby = {0, 0};

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (!visited[r][c]) {
                pair<int, int> ap = flood(r, c);
                if (ap.first > blobby.first) {
                    blobby = ap;
                }
                else if (ap.first == blobby.first && ap.second < blobby.second) {
                    blobby = ap;
                }
            }
        }
    }

    fout << blobby.first << " " << blobby.second << endl;
}