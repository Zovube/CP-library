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

int n;
int ff[MAXN];
int ans[MAXN];

void add(int i) {
	while(i <= n) {
		ff[i]++;
		i = (i | (i + 1));
	}
}

int f(int r) {
	int ans = 0;
	while(r >= 0) {
		ans += ff[r];
		r = (r & (r + 1)) - 1;
	}
	return ans;
}

int sum(int l, int r) {
	return f(r) - f(l - 1);
}

void input() {                  
	cin >> n;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		ans[x] = sum(x, n); // add elements one by one
		add(x);		    // for current watch how many elements greater than it we already had
	}
}

void solve() {          
	for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
}

int main() {     
#ifdef LOCAL
	freopen("xxx.in", "r", stdin);
	freopen("xxx.out", "w", stdout);
#else
	freopen("inversions.in", "r", stdin);
	freopen("inversions.out", "w", stdout);
#endif	
	input();
	solve();
	return 0;
}
