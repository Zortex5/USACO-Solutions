// https://usaco.org/index.php?page=viewproblem2&cpid=939

#include <fstream>
#include <iostream>

using std::ifstream, std::ofstream, std::endl, std::cout;


int main(void) {
    ifstream fin("buckets.in");
    ofstream fout("buckets.out");

    char c;
    int bx, by, rx, ry, lx, ly;
    int found = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            fin >> c;
            if (c == 'B') {
                bx = i;
                by = j;
                ++found;
            }
            else if (c == 'R') {
                rx = i;
                ry = j;
                ++found;
            }
            else if (c == 'L') {
                lx = i;
                ly = j;
                ++found;
            }
            if (found == 3) break;
        }
        if (found == 3) break;
    }
    // cout << bx << " " << by << endl << lx << " " << ly << endl << rx << " " << ry << endl;

    if (bx == lx  && lx == rx) {
        if (ly < by && ly < ry && ry < by) {
            fout << abs(ly - by) + 1 << endl;
        }
        else if (by < ly && by < ry && ry < ly) {
            fout << abs(ly - by) + 1 << endl;
        }
        else {
            fout << abs(ly - by) - 1 << endl;
        }
    }
    else if (by == ly  && ly == ry) {
        if (lx < bx && lx < rx && rx < bx) {
            fout << abs(lx - bx) + 1 << endl;
        }
        else if (bx < lx && bx < rx && rx < lx) {
            fout << abs(lx - bx) + 1 << endl;
        }
        else {
            fout << abs(lx - bx) - 1 << endl;
        }
    }
    else {
        fout << abs(lx - bx) + abs(ly - by) - 1 << endl;
    }
}