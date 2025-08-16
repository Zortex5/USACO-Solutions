// https://usaco.org/index.php?page=viewproblem2&cpid=919

#include <fstream>

using namespace std;

int wall[1001][1002];

int main() {
    ifstream fin("paintbarn.in");
    int n, k;
    fin >> n >> k;

    while (n--) {
        int x1, y1, x2, y2;
        fin >> x1 >> y1 >> x2 >> y2;

        for (int y = y1; y < y2; ++y) {
            ++wall[y][x1];
            --wall[y][x2];
        }
    }

    int total = 0;
    for (int y = 0; y < 1001; ++y) {
        int sum = 0;
        for (int x = 0; x < 1001; ++x) {
            sum += wall[y][x];
            if (sum == k) {
                ++total;
                //std::cerr << x << " " << y << endl;
            }
        }
    }

    ofstream fout("paintbarn.out");
    fout << total << endl;
}