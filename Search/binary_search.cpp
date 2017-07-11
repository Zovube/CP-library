#include<bits/stdc++.h>                               
using namespace std;

#define PI acos(-1)
#define pb push_back
#define sz(a) (int)(a).size()
#define all(c) (c).begin, (c).end()
#define TIMESTAMP fprintf(stderr, "Execution time: %.3lf s.\n", (double)clock()/CLOCKS_PER_SEC)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair <int, int> pii;
typedef vector <vi> vvi;
typedef vector <pii> vpii;
typedef vector<string> vs;

const int MAXN = 1;

int aa[MAXN];

void input() {
	for(int i = 0; i < MAXN; i++) cin >> aa[i];
}

void solve() {
	int x;
	cin >> x;
	int l = -1, r = MAXN;
	while(r - l > 1) {
		int m = (l + r) / 2;
		if(aa[m] < x) l = m;
		else r = m;
	}
    cout << r << ' ';
    l = -1, r = MAXN;
	while(r - l > 1) {
		int m = (l + r) / 2;
		if(aa[m] <= x) l = m;
		else r = m;
    	}
    cout << l << ' ';
}

int main() {
#ifdef LOCAL
	freopen("xxx.in", "r", stdin);
	freopen("xxx.out", "w", stdout);
#else
	//freopen("xxx.in", "r", stdin);
	//freopen("xxx.in", "r", stdin);
#endif	
	input();
	solve();
	return 0;
}
              	
