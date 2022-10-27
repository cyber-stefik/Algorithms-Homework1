#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Task {
 public:
    int n, k;
	vector<int> target, p;

    void solve() {
        read_input();
		prinel();
    }

    void read_input() {
        ifstream fin("prinel.in");
        fin >> n >> k;
        for (int i = 0; i < n; i++) {
			int number;
			fin >> number;
			target.push_back(number);
        }

		for (int i = 0; i < n; i++) {
			int number;
			fin >> number;
			p.push_back(number);
        }
        fin.close();
	}

	bool myKnapsack(int target) {
		ofstream fout("prinel.out");
		// cazul in care target este 1
		if (target == 1 && k >= 1) {
			return true;
		}
		int divisors[k], i;
		bool flag = false;
		// creez divizorii pentru numar
		for (i = 0; i < k; i++) {
			// primul numar este 1
			if (i == 0) {
				divisors[i] = 1;
				continue;
			}
			// presupun ca am calculat target-ul anterior si ma folosesc
			// de acest lucru pentru a verifica daca pot asigna elementului
			// curent dublul valorii elementului de dinainte
			if (divisors[i - 1] + divisors[i - 1] <= target) {
				divisors[i] = divisors[i - 1] + divisors[i - 1];
			} else {
				// caut cel mai mare element ce poate fi adaugat pana la
				// target
				for (int j = i - 2; j >= 0; j--) {
					if (divisors[i - 1] + divisors[j] <= target) {
						divisors[i] = divisors[i - 1] + divisors[j];
						break;
					}
				}
			}
			// true daca am ajuns la target
			if (divisors[i] == target) {
				flag = true;
				break;
			}
		}

		for (int j = 0; j < k; j++) {
			fout << divisors[i] << " ";
		}
		fout << endl;
		if (flag) {
			return true;
		}
		return false;
	}

	void prinel() {
		ofstream fout("prinel.out");
		int solution = 0;
		for (int i = 0; i < n; i++) {
			if (myKnapsack(target[i])) {
				solution += p[i];
			}
		}
		fout << solution << endl;
		fout.close();
	}
};

int main() {
    Task task;
    task.solve();
    return 0;
}
