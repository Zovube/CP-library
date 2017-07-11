#pragma GCC optimize("O3") 
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx") 
#define __USE_MINGW_ANSI_STDIO 0
#include<bits/stdc++.h>                               
using namespace std;

#define PI acos(-1)
#define pb push_back
#define fi first
#define se second
#define TASK "stupid_rmq"
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

int st[LOG2MAXN][MAXN], lg[MAXN];
int n;

void initST() {
	for(int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
	for(int i = 1; i < LOG2MAXN; i++) 
		for(int j = 0; j < n - (1 << (i - 1)); j++) 
			st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
}

int queryST(int l, int r) {
	int curlg = lg[r - l + 1];
	return min(st[curlg][l], st[curlg][r - (1 << (curlg)) + 1]);
}

void solve() {
	
}

void input() {	

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