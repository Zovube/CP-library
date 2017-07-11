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

const int MAXN = 1e5 + 9;
const int MOD = (int)(1e9 + 7);
const int LOG2MAXN = 17;
const int INF = 1e9;

int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
char ddir[] = {'R', 'U', 'L', 'D'};

// structure for maintaining Fenwick Tree
struct BIT {
	vll dataMul, dataAdd;
	int size, mxlog;
	
	// initialize BIT and calculate mxlog for binsearch
	void init(int nn) {
		mxlog = 0;
		while((1 << mxlog) < nn) mxlog++; 
		size = (1 << mxlog) + 1;
		dataMul.resize(size);
		dataAdd.resize(size);
	}
	
	// add linear function (mul * x + add) to [pos]
	void add(int pos, ll mul, ll add) {
		for(; pos < size; pos |= (pos + 1)) {
	 		dataMul[pos] += mul;
	 		dataAdd[pos] += add;
	 	}
	}
	
	// calculate sum on [0..pos]
	ll query(int pos) {
	 	ll mul = 0, add = 0, start = pos;
	 	for(; pos >= 0; pos = (pos & (pos + 1)) - 1) {
	 		mul += dataMul[pos];
	 		add += dataAdd[pos];
	 	}
	 	return mul * start + add;
	 }
	 
	 // add val to all elements on [l..r]
	 void add_range(int l, int r, ll val) {
	 	add(l, val, (l - 1) * -val);
	 	add(r, -val, r * val);
	 }
	 
	 // clculate sum on [l..r]
	 ll sum(int l, int r) {
	 	return query(r) - query(l - 1);
	 }
	 
	 // find k-th order statictic, almost binsearch
	 int kth(ll k) {
	 	int res = 0;
		for(int i = mxlog; i >= 0; i--) {
			if(dataAdd[res + (1 << i) - 1] < k) {	
				k -= dataAdd[res + (1 << i) - 1];
				res += ((1 << i));
			}
		}
		return res;	
	 }
	 	 
} bit; 
	 
// your code goes here :D

void input() {    

}

void solve() {
	
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
	return 0;
}
