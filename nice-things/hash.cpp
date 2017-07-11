#pragma GCC optimize("O3") 
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx") 
#define __USE_MINGW_ANSI_STDIO 0
#include<bits/stdc++.h>                               
using namespace std;

#define PI acos(-1)
#define pb push_back
#define fi first
#define se second
#define TASK "substrcmp"
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
	
const int MAXN = 5e5 + 9;
const int MOD = (int)(1e9 + 7);
const int LOG2MAXN = 20;
const int INF = 1e9;
const ld eps = 1e-9;

int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
char ddir[] = {'R', 'U', 'L', 'D'};

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int h[MAXN], p[MAXN], P;

void gen_hash(string s) {
	h[0] = 0;
	p[0] = 1;
	int n = sz(s);
	for(int i = 0; i < n; i++) {
		h[i + 1] = (h[i] * 1LL * P + s[i]) % MOD;
		p[i + 1] = (p[i] * 1LL * P) % MOD;
	}
}

int get_hash(int l, int r) {
	return (h[r + 1] - (h[l] * 1LL * p[r - l + 1]) % MOD + MOD) % MOD;
}

void input() {	
	string s;
	cin >> s;
	gen_hash(s);
	int m;
	cin >> m;
	for(int i = 0; i < m; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if(get_hash(a - 1, b - 1) == get_hash(c - 1, d - 1)) cout << "Yes\n";
		else cout << "No\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	P = max(239, (int)rnd());
#ifdef LOCAL
	freopen("xxx.in", "r", stdin);
	freopen("xxx.out", "w", stdout);
#else
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
#endif	
	input();
#ifdef LOCAL
	TIMESTAMP;
#endif	
	return 0;
}