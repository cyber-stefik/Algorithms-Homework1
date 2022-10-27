#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Task {
 public:
    int n, l;
	string key, substring;

    void solve() {
        read_input();
		crypto();
    }

    void read_input() {
        ifstream fin("crypto.in");
        fin >> n >> l;
		fin >> key;
		fin >> substring;
        fin.close();
    }

    int removeDuplicates(string str) {
        unordered_set<char> s;
        for (int i = 0; i < str.size(); i++) {
            s.insert(str[i]);
        }
        return s.size();
    }

    void vInit(vector<int>* v) {
        v->push_back(1);
        for (int i = 1; i <= l; i++) {
            v->push_back(0);
        }
    }

	void crypto() {
		ofstream fout("crypto.out");
        // numarul de litere unice din secventa
        long uniqueLetters = removeDuplicates(substring);
        // modulul cerut
        long modulo = pow(10, 9) + 7;
        vector<int> v;
        // vectorul initial, prezentat mai in detaliu in README
        vInit(&v);
        for (int i = 0; i < n; i++) {
            // o copie a vectorului actual
            vector<int> copyVector(v);
            // cazul unei litere
            if (key[i] != '?') {
                // parcurg fiecare litera din secventa si updatez vectorul
                for (int j = 0; j <= l; j++) {
                    if (key[i] == substring[j]) {
                        // rezultatul in modulo
                        v[j + 1] = (copyVector[j + 1] % modulo
                                    + copyVector[j] % modulo) % modulo;
                    }
                }
            } else {  // cazul ?
                for (int j = 0; j <= l; j++) {
                    // inmultez numarul de subsecvente curent cu numarul
                    // de litere unice
                    if (j != 0) {
                        v[j] = ((copyVector[j] * uniqueLetters) % modulo
                                + copyVector[j - 1] % modulo) % modulo;
                    } else {  // cazul special pentru index 0
                        v[0] = (v[0] * uniqueLetters) % modulo;
                    }
                }
            }
        }
        fout << v[l] << endl;
        fout.close();
	}
};

int main() {
    Task task;
    task.solve();
    return 0;
}
