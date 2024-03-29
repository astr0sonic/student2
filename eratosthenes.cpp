#include "eratosthenes.h"
#include <vector>

using namespace std;

void reshetoEratosphena(int n, bool*& t) {
	int i, j;
	for (j = 2; j * j <= n + 1; j++)
		for (i = j * j - 2; i < n; i += j)
			t[i] = false;
}

vector<int> sieve(int n) {
	vector<int> primes;
	bool* t = new bool[n - 1];
	for (i = 0; i < n - 1; i++)
		t[i] = true;
	reshetoEratosphena(n - 1, t);
	for (i = 0; i < n - 1; i++)
		if (t[i])
			primes.push_back(i + 2);
	delete[] t;
    return primes;
}

