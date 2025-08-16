// https://usaco.org/index.php?page=viewproblem2&cpid=833

#include <fstream>
#include <vector>
#include <map>
#include <iostream>

using std::ifstream, std::ofstream, std::vector, std::endl, std::tuple, std::map, std::string, std::get, std::cout;

string A, B;

vector<tuple<int, int, int>> graph[200];
string names[200];
map<string, int> indexOf;
int distance[200];
int level[200];


void dfs(int c, int p, int l, int d) {
    distance[c] = d;
    level[c] = l;

    for (tuple<int, int, int> &t : graph[c]) {
        if (get<0>(t) == p) continue;

        level[get<0>(t)] = l + get<1>(t);
        distance[get<0>(t)] = d + 1;

        dfs(get<0>(t), c, level[get<0>(t)], distance[get<0>(t)]);
    }
}


int main(void) {
    ifstream fin("family.in");
    int N, index = 0;
    fin >> N;
    fin >> A >> B;

    while (N--) {
        string x, y;
        fin >> x >> y;

        names[index] = x;
        names[index + 1] = y;
        if (!indexOf.count(x)) indexOf[x] = index++;
        if (!indexOf.count(y)) indexOf[y] = index++;

        graph[indexOf[x]].push_back({indexOf[y], -1, 0});
        graph[indexOf[y]].push_back({indexOf[x], 1, 0});
    }


    if (!indexOf.count(A) || !indexOf.count(B)) {
        ofstream fout("family.out");
        fout << "NOT RELATED" << endl;
        return 0;
    }

    int a = indexOf[A];
    int b = indexOf[B];
    

    dfs(a, -1, 0, 0);


    ofstream fout("family.out");
    int levelDiff = abs(level[b] - level[a]);

    if (distance[b] == 0) {
        fout << "NOT RELATED" << endl;
        return 0;
    }

    cout << level[a] << " " << level[b] << " " << endl;
    cout << level[a] << " " << level[b] << " " << level[2] << endl;
    cout << distance[a] << " " << distance[b] << " " << distance[2] << endl;

    if (levelDiff == distance[b]) {
        if (levelDiff == 1) {
            if (level[b] > level[a]) {
                fout << B << " is the mother of " << A << endl;
                return 0;
            }
            else {
                fout << A << " is the mother of " << B << endl;
                return 0;
            }
        }

        if (level[b] > level[a]) {
            fout << B << " is the ";
            for (int i = 2; i < levelDiff; ++i) {
                fout << "great-";
            }
            fout << "grand-mother of " << A << endl;
            return 0;
        }
        else {
            fout << A << " is the ";
            for (int i = 2; i < levelDiff; ++i) {
                fout << "great-";
            }
            fout << "grand-mother of " << B << endl;
            return 0;
        }
    }

    if (levelDiff == distance[b] - 2) {
        if (level[a] == level[b]) {
            fout << "SIBLINGS" << endl;
            return 0;
        }

        if (level[b] > level[a]) {
            fout << B << " is the ";
            for (int i = 1; i < levelDiff; ++i) {
                fout << "great-";
            }
            fout << "aunt of " << A << endl;
            return 0;
        }
        else {
            fout << A << " is the ";
            for (int i = 1; i < levelDiff; ++i) {
                fout << "great-";
            }
            fout << "aunt of " << B << endl;
            return 0;
        }
    }

    if (distance[b] > 0) {
        fout << "COUSINS" << endl;
        return 0;
    }
    else {
        fout << "NOT RELATED" << endl;
        return 0;
    }
}