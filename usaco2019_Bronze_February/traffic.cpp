// https://usaco.org/index.php?page=viewproblem2&cpid=917

#include <fstream>

using namespace std;

int ramps[100];
int a[100], b[100];

int main(void) {
    ifstream fin("traffic.in");
    int n;
    fin >> n;

    int start = 0, end = 1000;
    
    for (int i = 0; i < n; ++i) {
        string type;
        fin >> type;
        if (type == "on") {
            ramps[i] = 1;
            fin >> a[i] >> b[i];
            start += a[i];
            end += b[i];
        }
        else if (type == "off") {
            ramps[i] = -1;
            fin >> a[i] >> b[i];
            start -= b[i];
            end -= a[i];
        }
        else if (type == "none") {
            ramps[i] = 0;
            fin >> a[i] >> b[i];
            start = max(start, a[i]);
            end = min(end, b[i]);
        }
    }

    int s = 0, e = 1000;
    
    for (int i = n - 1; i >= 0; --i) {
        if (ramps[i] == 1) {
            s -= b[i];
            e -= a[i];
        }
        else if (ramps[i] == -1) {
            s += a[i];
            e += b[i];
        }
        else {
            s = max(s, a[i]);
            e = min(e, b[i]);
        }
    }

    if (start < 0) start = 0;
    if (end < 0) end = 0;
    if (s < 0) s = 0;
    if (e < 0) e = 0;
    ofstream fout("traffic.out");
    fout << s << " " << e << "\n";
    fout << start << " " << end << endl;
}