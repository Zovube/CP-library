#include<bits/stdc++.h>                               
using namespace std;

#define PI acos(-1)
#define fi first
#define se second
#define pb push_back
#define sz(a) (int)(a).size()
#define all(c) (c).begin(), (c).end()
#define TIMESTAMP fprintf(stderr, "Execution time: %.3lf s.\n", 1.0*clock()/CLOCKS_PER_SEC)

typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef pair <int, int> pii;
typedef vector <vi> vvi;
typedef vector <pii> vpii;
typedef vector <string> vs;
typedef vector <char> vch;

const int INF = 1e9;
const int MAXN = 1e5 + 9;
const int MOD = 1e9 + 7;

int n, m, s, f;
vpii gg[MAXN];
vi dd(MAXN), pp(MAXN);
set <pii> st;

void dijkstra() {
	fill(all(dd), INF);
	dd[s] = 0, pp[s] = -1;
	st.insert({ dd[s], s });
	while(!st.empty()) {
		int v = st.begin()->se;
		st.erase(st.begin());  
		for(int i = 0; i < sz(gg[v]); i++) {
			int to = gg[v][i].fi,
				len = gg[v][i].se;
			if(dd[to] > dd[v] + len) {
				st.erase({ dd[to], to });
				dd[to] = dd[v] + len;
				pp[to] = v;
				st.insert({ dd[to], to });
			}
		}
	}
}


void input() {                  
	cin >> n >> s >> f;
	s--, f--;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			int x;
			cin >> x;
			if(x >= 0) {
				gg[i].pb({ j, x });
			}
		}
	}
}

void solve() {                        
	dijkstra();
	cout << (dd[f] == INF ? -1 : dd[f]) << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);     
#ifdef LOCAL
	freopen("xxx.in", "r", stdin);
	freopen("xxx.out", "w", stdout);
#else
	freopen("INPUT.TXT", "r", stdin);
	freopen("OUTPUT.TXT", "w", stdout);
#endif	
	input();
	solve();
	return 0;
}
