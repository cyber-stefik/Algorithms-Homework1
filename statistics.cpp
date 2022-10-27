#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Task {
 public:
    int n;
	vector<string> words;

    void solve() {
        read_input();
		statistics();
    }

    void read_input() {
        ifstream fin("statistics.in");
        fin >> n;
        for (int i = 0; i < n; i++) {
			string word;
			fin >> word;
			words.push_back(word);
        }
        fin.close();
    }

	void statistics() {
		ofstream fout("statistics.out");
		int max = INT_MIN;
		// parcurg toate literele alfabetului englez
		for (char c = 'a'; c <= 'z'; c++) {
			// calculez dominanta pentru fiecare litera din alfabet
			vector<int> transferredChars = transferChars(words, c);
			// sortez descrescator
			sort(transferredChars.begin(), transferredChars.end(),
				[](const int a, const int b) { return a > b;});
			int sum = 0;
			int i;
			for (i = 0; i < transferredChars.size(); i++) {
				// adaug orice este pozitiv
				if (transferredChars[i] >= 0) {
					sum += transferredChars[i];
				}
				// verific daca suma este pozitiva chiar daca adaug
				// o dominanta negativa
				if (transferredChars[i] < 0) {
					if (sum > -transferredChars[i]) {
						sum += transferredChars[i];
					} else {
						break;
					}
				}
			}
			// updatez secventa maxima
			if (max < i) {
				max = i;
			}
		}
		fout << max << endl;
		fout.close();
	}

	vector<int> transferChars(vector<string> wordsCopy, char character) {
		vector<int> transferredChars;
		// parcurg fiecare cuvant
		for (auto& word : wordsCopy) {
			int dominantSize = 0;
			int different = 0;
			for (auto& ch : word) {
				// ii calculez dominanta
				if (ch == character) {
					dominantSize++;
				} else {
					different++;
				}
			}
			// diferenta lor este dominanta in cuvant
			transferredChars.push_back(dominantSize - different);
		}
		return transferredChars;
	}
};

int main() {
    Task task;
    task.solve();
    return 0;
}
