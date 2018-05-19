#include "stringAlgorithms.h"

int editDistance(string pattern, string text) { //comlexidade O T
	vector<int> D;
	int m=pattern.length();
	int n=text.length();
	for (int i = 0; i < m+1; i++)
		D.push_back(i);
	int oldN, newN;
	for (int i = 1; i < n+1; i++) {
		oldN = D[0];
		D[0] = i;
		for (int j = 1; j <= m; j++) {
			if (text[i - 1] == pattern[j - 1])
				newN = oldN;
			else
				newN = 1 + min(min(oldN, D[j]), D[j - 1]);
			oldN = D[j];
			D[j] = newN;
		}
	}
	return D[m];
}
