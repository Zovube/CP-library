#include<bits/stdc++.h>                               
using namespace std;

#define PI acos(-1)
#define fi first
#define se second
#define pb push_back
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
typedef vector<string> vs;

const int INF = 100500;
const int MAXN = 1e5 + 9;
const int MOD = 1e9 + 7;

ll ff[MAXN];
ll n, m;

void add(int pos, ll val) {
	while(pos < MAXN) {
		ff[pos] += val;
		pos = (pos | (pos + 1)); //pos + least significant bit of pos
	}
}
 
// sum on [0, r]
ll query(int r) {
	ll ans = 0;
	while(r >= 0) {
		ans += ff[r];
		r = (r & (r + 1)) - 1; //pos - least significant bit of pos
	}
	return ans;
}

ll sum(int l, int r) {
	return query(r) - query(l - 1);
}

void input() {                  
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		add(i, x);
	}
}

void solve() {          
	for(int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		cout << sum(l, r) << endl;
	}
}

int main() {     
#ifdef LOCAL
	freopen("xxx.in", "r", stdin);
	freopen("xxx.out", "w", stdout);
#else
	freopen("rsq.in", "r", stdin);
	freopen("rsq.out", "w", stdout);
#endif	
	input();
	solve();
	return 0;
}
