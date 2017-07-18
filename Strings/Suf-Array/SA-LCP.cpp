#pragma GCC optimize("O3") 
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx") 
#define __USE_MINGW_ANSI_STDIO 0
#include<bits/stdc++.h>                               
using namespace std;

#define PI acos(-1)
#define pb push_back
#define fi first
#define se second
#define TASK "towers"
#define sz(a) (int)(a).size()
#define all(c) (c).begin(), (c).end()
#define TIMESTAMP fprintf(stderr, "Execution time: %.3lf s.\n", (double)clock()/CLOCKS_PER_SEC)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair <int, int> pii;
typedef vector <vi> vvi;
typedef vector <pii> vpii;
typedef vector <string> vs;
	
const int MAXN = 5e4 + 9;
const int MOD = (int)(1e9 + 7);
const int LOG2MAXN = 17;
const int INF = 1e9;
const ld eps = 1e-9;

int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
char ddir[] = {'R', 'U', 'L', 'D'};

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int n;
char s[MAXN];

const int maxlen = MAXN;
const int alphabet = 256;

int p[maxlen], cnt[maxlen], c[maxlen];
int pn[maxlen], cn[maxlen];
int lcp[maxlen], lcpn[maxlen], lpos[maxlen], rpos[maxlen];
int tt[4 * MAXN];

void build(int v, int l, int r) {
	if(l == r - 1) {
		tt[v] = lcp[l];
		return;
	}
	int m = (l + r) / 2;
	build(v * 2 + 1, l, m);
	build(v * 2 + 2, m, r);
	tt[v] = min(tt[v * 2 + 1], tt[v * 2 + 2]);
}

int query(int v, int l, int r, int ql, int qr) {
	if(ql >= r || qr <= l) return INF;
	if(ql <= l && qr >= r) return tt[v];
	int m = (l + r) / 2;
	int a = query(v * 2 + 1, l, m, ql, qr);
	int b = query(v * 2 + 2, m, r, ql, qr);
	return min(a, b);
}

void build_SA() {
	memset(cnt, 0, alphabet * 4);
	for(int i = 0; i < n; i++) cnt[s[i]]++;
	for(int i = 1; i < alphabet; i++) cnt[i] += cnt[i - 1];
	for(int i = 0; i < n; i++) p[--cnt[s[i]]] = i;
	c[p[0]] = 0;
	int classes = 1;
	for(int i = 1; i < n; i++) {
		if(s[p[i]] != s[p[i- 1]]) classes++;
		c[p[i]] = classes - 1;
	}
	memset (lcp, 0, sizeof lcp);
	for(int h = 0; (1 << h) <= n; h++) {
		for(int i = 0; i < n; i++) rpos[c[p[i]]] = i;
		for(int i = n - 1; i >= 0; i--) lpos[c[p[i]]] = i;
		for(int i = 0; i < n; i++) {
			pn[i] = p[i] - (1 << h);
			if(pn[i] < 0) pn[i] += n;
		}
		memset(cnt, 0, classes * 4);
		for(int i = 0; i < n; i++) cnt[c[pn[i]]]++;
		for(int i = 1; i < classes; i++) cnt[i] += cnt[i - 1];
		for(int i = n - 1; i >= 0; i--) p[--cnt[c[pn[i]]]] = pn[i];
		cn[p[0]] = 0;
		classes = 1;
		for(int i = 1; i < n; i++) {
			int mid1 = p[i] + (1 << h);
			if(mid1 >= n) mid1 -= n;
			int mid2 = p[i - 1] + (1 << h);
			if(mid2 >= n) mid2 -= n;
			if(c[p[i]] != c[p[i - 1]] || c[mid1] != c[mid2]) classes++;
			cn[p[i]] = classes - 1;
		}	
		build(0, 0, n);
		for(int i = 0; i < n - 1; i++) {
			int a = p[i], b = p[i + 1];
			if(c[a] != c[b]) lcpn[i] = lcp[rpos[c[a]]];
			else {
				int aa = (a + (1 << h));
				if(aa >= n) aa -= n;
				int bb = (b + (1 << h));
				if(bb >= n) bb -= n;
				if(c[aa] != c[bb]) lcpn[i] = (1 << h) + query(0, 0, n, lpos[c[aa]], rpos[c[bb]]);
				else lcpn[i] = n;
				lcpn[i] = min(n, lcpn[i]);
			}
		}
		memcpy(lcp, lcpn, (n - 1) * 4);
		memcpy(c, cn, (n) * 4);
	}
}

void solve() {
	
}

void input() {
	
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#ifdef LOCAL
	freopen("xxx.in", "r", stdin);
	freopen("xxx.out", "w", stdout);
#else
	//freopen(TASK".in", "r", stdin);
	//freopen(TASK".out", "w", stdout);
#endif	
	input();
	solve();
#ifdef LOCAL
	TIMESTAMP;
#endif	
	return 0;
}