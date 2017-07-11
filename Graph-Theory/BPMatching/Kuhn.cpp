#pragma GCC optimize("O3") 
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx") 
#define __USE_MINGW_ANSI_STDIO 0
#include<bits/stdc++.h>                               
using namespace std;

#define PI acos(-1)
#define pb push_back
#define fi first
#define se second
#define TASK "pairs"
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
	
const int MAXN = 5e2 + 9;
const int MOD = (int)(1e9 + 7);
const int LOG2MAXN = 17;
const int INF = 1e9;
const ld eps = 1e-9;

int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
char ddir[] = {'R', 'U', 'L', 'D'};

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int n, m, mt[MAXN], rmt[MAXN];
char used[MAXN];
vi gg[MAXN];

bool try_kuhn(int v) {
	used[v] = 1;
	for(auto to : gg[v]) 
		if(mt[to] == -1 || (mt[to] != -1 && !used[mt[to]] && try_kuhn(mt[to]))) {
			mt[to] = v;
			rmt[v] = to;
			return 1;
		}
	return 0;
}

void solve() {
	memset(mt, -1, sizeof(mt));
	memset(rmt, -1, sizeof(rmt));
	while(1) {
		bool any = 0;
		memset(used, 0, sizeof(used));
		for(int i = 0; i < n; i++) 
			if(rmt[i] == -1)
				any |= try_kuhn(i);
		if(!any) break;
	}
	vpii ans;
	for(int i = 0; i < n; i++) if(rmt[i] != -1) ans.pb({i + 1, rmt[i] + 1});
	cout << sz(ans) << endl;
	for(auto x : ans) cout << x.fi << ' ' << x.se << endl; 
}

void input() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		int x;
		while(1) {
			cin >> x;
			if(x == 0) break;
			gg[i].pb(x - 1);
		}
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