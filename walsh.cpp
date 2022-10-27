#include <bits/stdc++.h>
#include <vector>

using namespace std;

struct coord {
    int x;
    int y;

    coord(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

class Task {
 public:
    int n, k;
    vector<coord> coords;

    void solve() {
        read_input();
        walsh();
    }

    void read_input() {
        ifstream fin("walsh.in");
        fin >> n;
        fin >> k;
        int auxx, auxy;
        for (int i = 0; i < k; i++) {
            fin >> auxx >> auxy;
            coords.push_back(coord(auxx, auxy));
        }
        fin.close();
    }

    void walsh() {
        ofstream fout("walsh.out");
        for (int i = 0; i < k; i++) {
            fout << checkWalsh(coords[i].x, coords[i].y, n, false) << endl;
        }
        fout.close();
    }

    int checkWalsh(int x, int y, int no, bool rev) {
        // coltul dreapta jos, caz special
        if (x == n && y == n) {
            return 1;
        }
        // rezultatul
        if (no == 1) {
            // in functie de flag, returnez valoarea corecta
            if (rev == false) {
                return 0;
            } else {
                return 1;
            }
        }
        // cadranul 1
        if (x <= no / 2 && y <= no / 2) {
            return checkWalsh(x, y, no / 2, rev);
        }
        // cadranul 2
        if (x <= no / 2 && y >= no / 2) {
            return checkWalsh(x, y - no / 2, no / 2, rev);
        }
        // cadranul 3
        if (x >= no / 2 && y <= no / 2) {
            return checkWalsh(x - no / 2, y, no / 2, rev);
        }
        // cadranul 4
        if (x >= no / 2 && y >= no / 2) {
            return checkWalsh(x - no / 2, y - no / 2, no / 2, !rev);
        }
        return -1;
    }
};

int main() {
    Task task;
    task.solve();
    return 0;
}
