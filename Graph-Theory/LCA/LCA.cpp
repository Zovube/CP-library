#pragma GCC optimize("O3") 
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx") 
#define __USE_MINGW_ANSI_STDIO 0
#include<bits/stdc++.h>                               
using namespace std;

#define PI acos(-1)
#define pb push_back
#define fi first
#define se second
#define TASK "lca"
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
const int LOG2MAXN = 17;
const int INF = 1e9;
const ld eps = 1e-9;

int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
char ddir[] = {'R', 'U', 'L', 'D'};

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

vpii qq;
vvi gg;
int dp[LOG2MAXN][MAXN];
int n, dd[MAXN];
char used[MAXN];

void dfs(int v, int dep) {
	used[v] = 1;
	dd[v] = dep;
	for(auto to : gg[v]) 
		if(!used[to]) {
			dp[0][to] = v;
			dfs(to, dep + 1);
		}
}

int lca(int u, int v) {
	if(dd[u] > dd[v]) swap(u, v);
	for(int i = LOG2MAXN - 1; i >= 0; i--) 
		if(dd[v] - dd[u] >= (1 << i))
			v = dp[i][v];
	if(u == v) return u;
	for(int i = LOG2MAXN - 1; i >= 0; i--)
		if(dp[i][v] != dp[i][u]) {
			u = dp[i][u];
			v = dp[i][v];
		}
	return dp[0][u];
}

void solve() {
	dfs(0, 0);
	for(int i = 1; i < LOG2MAXN; i++)
		for(int j = 0; j < n; j++) 
			dp[i][j] = dp[i - 1][dp[i - 1][j]];
	for(auto x : qq) cout << lca(x.fi, x.se) + 1 << "\n";
}

void input() {
	cin >> n;
	gg.resize(n);
	for(int i = 0; i < n; i++) {
		string s;
		int u, v;
		cin >> s >> u >> v;
		u--, v--;
		if(s[0] == 'A') {
			gg[u].pb(v);
			gg[v].pb(u);
		}
		else qq.pb({u, v});
	}
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