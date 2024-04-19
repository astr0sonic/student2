#include "kmp.h"
#include <vector>

using namespace std;

int* arrayPrefixSuffix(const string& s, int l) {
	int* p = new int[l];
	p[0] = 0;
	int i = 1, j = 0;
	while (j < l && i < l) {
		if (s[i] == s[j]) {
			p[i] = j + 1;
			i++; j++;
		}
		else
			if (j == 0) {
				p[i] = 0; i++;
			}
			else
				j = p[j - 1];
	}
	return p;
}

vector<int> findAllSubstrings(const string& text, const string& s, int* p, int n) {
	vector<int> vect;
	int i = 0, j = 0, N = text.length();
	while (i < N) {
		if (text[i] == s[j]) {
			i++; j++;
			if (j == n)
				vect.push_back(i - n);
		}
		else if (j == 0)
			i++;
		else
			j = p[j - 1];
	}
	return vect;
}

vector<int> getIndices(const string& my_template, const string& text) {
	int n = my_template.size();
	auto p = arrayPrefixSuffix(my_template, n);
	auto result = findAllSubstrings(text, my_template, p, n);
	delete[] p;
    return result;
}

