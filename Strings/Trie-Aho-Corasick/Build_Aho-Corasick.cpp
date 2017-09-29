#pragma GCC optimize("O3") 
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx") 
#define __USE_MINGW_ANSI_STDIO 0
#include<bits/stdc++.h>                               
using namespace std;

#define PI acos(-1)
#define pb push_back
#define fi first
#define se second
#define TASK ""
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
	
const int MAXN = 1e3 + 9;
const int MOD = (int)(1e9 + 7);
const int LOG2MAXN = 17;
const int INF = 1e9;
const ld eps = 1e-9;
const int sigma = 26 * 2;

int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
char ddir[] = {'R', 'U', 'L', 'D'};

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int term[MAXN * MAXN], to[MAXN * MAXN][sigma], link[MAXN * MAXN], pos[MAXN * MAXN], ans[MAXN], sz = 1;
map < string, int > mp;


int get(char c) {
	return (c >= 'a' && c <= 'z') ? c - 'a' : 26 + c - 'A';
}

void init() {
	mp.clear();
	mp["#"] = 100500;
	memset(term, 0, sizeof(term));
	memset(to, 0, sizeof(to));
	memset(link, 0, sizeof(link));
	memset(pos, 0, sizeof(pos));
	memset(ans, 0, sizeof(ans));
	sz = 1;
}

int get_id(string s) {
	if(mp[s] == 0) mp[s] = sz(mp);
	return mp[s];
}

void add_string(string &s) {
	int cur = 0;
	for(auto x : s) {
		int c = get(x);
		if(!to[cur][c]) {
			to[cur][c] = sz++;
		}
		cur = to[cur][c];
	}	
	term[cur] = cur;
	pos[cur] = get_id(s);
}

void push_links() {
	int que[sz];
	int st = 0, fi = 1;
	que[0] = 0;
	while(st < fi) {
		int V = que[st++];
		int U = link[V];
		if(!term[V]) term[V] = term[U];
		for(int c = 0; c < sigma; c++) {
			if(to[V][c]) {
				link[to[V][c]] = V ? to[U][c] : 0;
				que[fi++] = to[V][c];
			}
			else {
				to[V][c] = to[U][c];
			}
		}
	}
}

void solve() {

}

void input() {
	init();
	string t; cin >> t;
	int q; cin >> q;
	vector < string > s(q);
	for(int i = 0; i < q; i++) {
		cin >> s[i];
		add_string(s[i]);
	}
	int cur = 0;
	push_links();
	for(auto x : t) {
		int c = get(x);
		cur = to[cur][c];
		int v = term[cur];
		while(v) {
			if(term[v] == v) 
				ans[pos[v]] = 1;
			v = term[link[v]];
		}
	}
	for(int i = 0; i < q; i++) {
		if(ans[get_id(s[i])]) cout << 'y' << '\n';
		else cout << 'n' << '\n';
	}
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
	int tt;
	cin >> tt;
	while(tt--) {
		input();
		solve();
	}
#ifdef LOCAL
	TIMESTAMP;
#endif	
	return 0;
}