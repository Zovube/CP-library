#pragma GCC optimize("O3") 
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx") 
#define __USE_MINGW_ANSI_STDIO 0
#include<bits/stdc++.h>                               
using namespace std;

#define PI acos(-1)
#define pb push_back
#define fi first
#define se second
#define TASK "bridges"
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
	
const int MAXN = 1e5 + 9;
const int MOD = (int)(1e9 + 7);
const int LOG2MAXN = 17;
const int INF = 1e9;
const ld eps = 1e-9;

int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
char ddir[] = {'R', 'U', 'L', 'D'};

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

vvi gg;
char used[MAXN];
int n, m;
map < pii, int > id;
map < pii, int > cnt;
int tin[MAXN], fup[MAXN], timer;
vi bridges;
set < int > cutPoints;

void dfs(int v, int p = -1) {
	used[v] = 1;
	tin[v] = fup[v] = timer++;
	int ch = 0;
	for(auto to : gg[v]) {
		if(to == p) continue;
		if(used[to]) fup[v] = min(fup[v],tin[to]);
		else {
			dfs(to, v);
			fup[v] = min(fup[v], fup[to]);
			if(tin[v] < fup[to] && cnt[{min(to, v), max(to, v)}] < 2) bridges.pb(id[{min(to, v), max(to, v)}]);
			if(p != -1 && tin[v] <= fup[to]) cutPoints.insert(v);
			ch++;
		}
	}
	if(p == -1 && ch > 1) cutPoints.insert(v);
}

void solve() {
	for(int i = 0; i < n; i++) if(!used[i]) dfs(i);  
	// your code goes here...
}

void input() {
	cin >> n >> m;
	gg.resize(n);
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		gg[u].pb(v);
		gg[v].pb(u);
		if(u > v) swap(u, v);
		id[{u, v}] = i + 1;
		cnt[{u, v}]++;
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