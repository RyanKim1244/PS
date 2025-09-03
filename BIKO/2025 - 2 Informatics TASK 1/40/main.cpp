#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

ll N, M, Q;
ll par[250005], K[250005], p[250005], r[250005], S[250005];
bool check[250005];

vector<int> V[250005];

void tree(ll number) {
	for (int element : V[number]) {
		if (element != par[number]) par[element] = number, tree(element);
	}
}

int seek(ll k) {
	if (k == p[k]) return k;
	else return p[k] = seek(p[k]);
}

void Union(ll x, ll y) {
	x = seek(x), y = seek(y);

	if (x == y) return;

	p[y] = x, S[x] += S[y];
}

int main(void) {
	int i, j;
	ll a, b;
	long long int ans = 0;

	scanf("%lld", &N);
	for (i = 1; i < N; i++) {
		scanf("%lld %lld", &a, &b);
		V[a].push_back(b), V[b].push_back(a);
	}

	tree(1);

	scanf("%lld", &Q);
	for (i = 1; i <= Q; i++) {
		scanf("%lld", &M);
		for (j = 1; j <= M; j++) scanf("%lld", &K[j]), check[K[j]] = true, p[K[j]] = K[j], r[K[j]] = 1, S[K[j]] = 1;

		for (j = 1; j <= M; j++) {
			if (check[par[K[j]]]) {
				Union(K[j], par[K[j]]);
			}
		}

		for (j = 1; j <= M; j++) {
			if (p[K[j]] == K[j]) ans += ll(S[K[j]] * (S[K[j]] - 1) / 2);
			check[K[j]] = false;

			p[K[j]] = K[j], r[K[j]] = 1, S[K[j]] = 1;
		}

		printf("%lld\n", ans);
		ans = 0;
	}
}
