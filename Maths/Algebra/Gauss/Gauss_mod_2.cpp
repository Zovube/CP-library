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

int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
char ddir[] = {'R', 'U', 'L', 'D'};

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int n;

int gauss(vector < bitset < MAXN > > a, int n, int m, bitset < MAXN > & ans) {
	vector < int > where (m, -1);
	for(int col = 0, row = 0; col < m && row < n; ++col) {
		for(int i = row; i < n; ++i)
			if(a[i][col]) {
				swap(a[i], a[row]);
				break;
			}
		if(!a[row][col])
			continue;
		where[col] = row;
		for(int i = 0; i < n; ++i)
			if(i != row && a[i][col])
				a[i] ^= a[row];
		++row;
	}
	for(int i = 0; i < m; i++) {
		if(where[i] != -1) 
			ans[i] = a[where[i]][m];
	}
	for (int i=0; i<n; ++i) {
		int sum = 0;
		for (int j=0; j<m; ++j)
			sum += ans[j] * a[i][j];
		if (sum != a[i][m])
			return 0;
	}
	return 1;
}

void input() {
	cin >> n;
	vector < bitset < MAXN > > aa(n);
	bitset < MAXN >  ans;
	for(int i = 0; i < n; i++) {
		int x = 0;
		while(1) {
			cin >> x;
			if(x == -1) break;
			x--;
			aa[x].set(i);
		}
	}
	for(int i = 0; i < n; i++) aa[i][n + 1] = 1;
	if(gauss(aa, n, n + 1, ans)) {
		for(int i = 0; i < n; i++) if(ans[i]) cout << i + 1 << ' ';
	}
	else cout << "No solution";
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
	input();
	solve();
#ifdef LOCAL
	TIMESTAMP;
#endif	
	return 0;
}