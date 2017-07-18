#pragma GCC optimize("O3") 
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx") 
#define __USE_MINGW_ANSI_STDIO 0
#include<bits/stdc++.h>                               
using namespace std;

#define PI acos(-1)
#define pb push_back
#define fi first
#define se second
#define TASK "cyclic"
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
	
const int MAXN = 1e6 + 9;
const int MOD = (int)(1e9 + 7);
const int LOG2MAXN = 17;
const int INF = 1e9;
const ld eps = 1e-9;

int n;
char s[MAXN];

const int maxlen = MAXN;
const int alphabet = 128 * 2;

void build_SA() {
	int p[maxlen], cnt[maxlen], c[maxlen];
	memset(cnt, 0, alphabet * sizeof(int));
	for(int i = 0; i < n; i++) cnt[s[i]]++;
	for(int i = 1; i < alphabet; i++) cnt[i] += cnt[i - 1];
	for(int i = 0; i < n; i++) p[--cnt[s[i]]] = i;
	c[p[0]] = 0;
	int classes = 1;
	for(int i = 1; i < n; i++) {
		if(s[p[i]] != s[p[i - 1]]) classes++;
		c[p[i]] = classes - 1;
	}
	int pn[maxlen], cn[maxlen];
	for(int h = 0; (1 << h) < n; h++) {
		for(int i = 0; i < n; i++) {
			pn[i] = p[i] - (1 << h);
			if(pn[i] < 0) pn[i] += n;
		}
		memset(cnt, 0, classes * sizeof(int));
		for(int i = 0; i < n; i++) cnt[c[pn[i]]]++;
		for(int i = 0; i < classes - 1; i++) cnt[i + 1] += cnt[i];
		for(int i = n - 1; i >= 0; i--) p[--cnt[c[pn[i]]]] = pn[i];
		cn[p[0]] = 0;
		classes = 1;
		for(int i = 1; i < n; i++) {
			int mid1 = (p[i] + (1 << h)), mid2 = (p[i - 1] + (1 << h));
			if(mid1 >= n) mid1 -= n;
			if(mid2 >= n) mid2 -= n;
			if(c[p[i]] != c[p[i - 1]] || c[mid1] != c[mid2]) classes++;
			cn[p[i]] = classes - 1;
		}
		memcpy(c, cn, n * sizeof(int));
	}
}

void solve() {
	build_SA();	
}

void input() {
	gets(s);
	n = strlen(s);
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#ifdef LOCAL
	freopen("xxx.in", "r", stdin);
	freopen("xxx.out", "w", stdout);
#else
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
#endif	
	input();
	solve();
#ifdef LOCAL
	TIMESTAMP;
#endif	
	return 0;
}
