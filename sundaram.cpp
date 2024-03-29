#include "sundaram.h"
#include <vector>

using namespace std;

void reshetoSundarama(int n, bool*& t) {
	int i, j;
	for (i = 1; i <= (sqrt(2 * n + 1) - 1) / 2; i++)
		for (j = i; j <= (n - i) / (2 * i + 1); j++)
			t[i + j + 2 * i * j - 1] = false;
}

vector<int> sieve(int n) {
    vector<int> primes;
	int i;
	primes.push_back(2);
	n = (n + 1) / 2 - 1;
	bool* t = new bool[n];
	for (i = 0; i < n; i++)
		t[i] = true;
	reshetoSundarama(n, t);
	for (i = 0; i < n; i++)
		if (t[i])
			primes.push_back(2 * i + 3);
	delete[] t;
    return primes;
}
