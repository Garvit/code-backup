//c++ 11
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <cassert>
#include <climits>
#include <inttypes.h>
#include <unordered_map>
using namespace std;
long long MOD, pf[1000005], bin[15][15];
int K;
unordered_map<long long, long long> sumMemo[15], memo[15];
unordered_map<long long, long long>::iterator it;
long long add(long long a, long long b) {
	a += b;
	if (a >= MOD) a -= MOD;
	return a;
}
long long mult(long long a, long long b) {
	// Calculates a * b (mod MOD) where a and b can be up to MOD
	if (!b) return 0;
	if (b & 1) return add(mult(a, b - 1), a);
	if (b & 3) {
		long long v = mult(a, b >> 1);
		return add(v, v);
	}
	long long v = mult(a, b >> 2);
	return (4 * v) % MOD;
}
long long fastPow(long long n, int k) {
	if (!k) return add(1, 0);
	it = memo[k].find(n);
	if (it != memo[k].end()) return it->second;
	long long &ret = memo[k][n];
	// Calculates n^K
	if (k & 1) return ret = mult(fastPow(n, k - 1), n);
	long long half = fastPow(n, k >> 1);
	return ret = mult(half, half);
}
long long sumPow(long long n, int k) {
	// Calculates 1^K + 2^K + ... + n^K (mod MOD)
	if (!n) return 0;
	it = sumMemo[k].find(n);
	if (it != sumMemo[k].end()) return it->second;
	long long &ret = sumMemo[k][n];
	if (n & 1) return ret = add(sumPow(n - 1, k), fastPow(n, k));
	n >>= 1;
	ret = sumPow(n, k);
	for (int i = 0; i <= k; ++i) {
		ret = add(ret, mult(bin[k][i], mult(fastPow(n, k - i), sumPow(n, i))));
	}
	return ret;
}
int main() {
	int pn = 0;
	long long N, NN, ans = 0;
	scanf("%lld%d%lld", &N, &K, &MOD);
	for (int i = 0; i <= K; ++i)
		for (int j = 0; j <= i; ++j)
			if (!j || j == i) bin[i][j] = 1 % MOD;
			else bin[i][j] = (bin[i - 1][j - 1] + bin[i - 1][j]) % MOD;
	NN = N;
	long long p = 2;
	while (p * p <= N) {
		if (N % p == 0) {
			while (N % p == 0) N /= p;
			pf[pn++] = p;
		}
		++p;
	}
	if (N != 1) pf[pn++] = N;
	for (int i = 0; i < (1 << pn); ++i) {
		long long fac = 1;
		int coeff = 1;
		for (int j = 0; j < pn; ++j)
			if (i & (1 << j)) {
				fac *= pf[j];
				coeff = -coeff;
			}
		long long v = mult(fastPow(fac, K), sumPow(NN / fac, K));
		ans = add(ans, coeff * v);
		if (ans < 0) ans += MOD;
//		printf("%lld %lld %d %lld %lld\n", fac, v, coeff, fastPow(fac, K), sumPow(NN / fac));
	}
	printf("%lld\n", ans);
}
