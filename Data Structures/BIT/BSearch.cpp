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
const int MAXPOW = 17;
const int MAXN = 1 << MAXPOW + 1;
const int MOD = 1e9 + 7;

int n, m;
int ff[MAXN];

void add(int i, int val) {
	while(i < MAXN) {
		ff[i] += val;
		i += (i & -i); // true LSB
	}
}

int bin_search(int x) {
	if(x > ff[1 << MAXPOW]) return -1; // sum af all is ff[1 << MAXPOW]
	int sum = 0; // initial sum
	int pos = 0; // inintial position
	// try oll binary powers and try to maximize position
	for(int i = 1 << MAXPOW; i && pos + i < MAXN; i >>= 1) {    
		if(sum + ff[pos + i] < x) {
			sum += ff[pos + i];
			pos += i;
		}
	}
	// + 1 because we find FIRST LESS than x => next includes x
	return pos + 1;
}

void input() {                  
	cin >> n;
	for(int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		add(i, x);
	}
}

void solve() {          
	cin >> m;
	for(int i = 0; i < m; i++) {
		int x;
		cin >> x;
		cout << bin_search(x) << endl;
	}
}

int main() {     
#ifdef LOCAL
	freopen("xxx.in", "r", stdin);
	freopen("xxx.out", "w", stdout);
#else
	//freopen("xxx.in", "r", stdin);
	//freopen("xxx.out", "w", stdout);
#endif	
	input();
	solve();
	return 0;
}
