#pragma GCC optimize("O3") 
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx") 
#define __USE_MINGW_ANSI_STDIO 0
#include<bits/stdc++.h>                               
using namespace std;

#define PI acos(-1)
#define pb push_back
#define fi first
#define se second
#define TASK "invtrans"
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

void solve() {
	
}

vi z_f(vi s) {
	int n = sz(s);
	vi z(n, 0);
	for(int i = 1, l = 0, r = 0; i < n; i++) {
		if(i <= r) z[i] = min(z[i - l], r - i + 1);
		while(i + z[i] < n && s[i + z[i]] == s[z[i]]) z[i]++;
		if(i + z[i] - 1 > r) r = i + z[i] - 1, l = i;
	}
	return z;
}

void input() {
	int n;
	cin >> n;
	vi pi(n, 0), z(n, 0), s(n, 0);
	for(int i = 0; i < n; i++) {
		cin >> pi[i];
		s[i] = i;
	}
	for(int i = 0; i < n; i++) 
		if(pi[i])
			s[i] = s[pi[i] - 1];
	z = z_f(s);
	z[0] = n;
	for(auto x : z) cout << x << ' '; 	
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