#pragma GCC optimize("O3") 
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx") 
#define __USE_MINGW_ANSI_STDIO 0
#include<bits/stdc++.h>                               
using namespace std;

#define PI acos(-1)
#define pb push_back
#define fi first
#define se second
#define TASK "hull"
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

struct Vector {
	int x, y;
	
	Vector() {}
	Vector(Vector a, Vector b) : x(b.x - a.x), y(b.y - a.y) {}
	ll operator* (const Vector & a) {
		return x * 1LL * a.y - y * 1LL * a.x;
	}
};

bool cw(Vector a, Vector b, Vector c) {
	return Vector(b, c) * Vector(b, a) < 0;
}

bool ccw(Vector a, Vector b, Vector c) {
	return Vector(b, c) * Vector(b, a) > 0;
}

bool cmp(Vector a, Vector b) {
	return a.x < b.x || a.x == b.x && a.y < b.y;
}

void ch(vector < Vector > & pp) {
	if(sz(pp) == 1) return;
	sort(all(pp), cmp);
	Vector p1 = pp[0], p2 = pp.back();
	vector < Vector > up, down;
	up.pb(p1), down.pb(p1);
	int n = sz(pp);
	for(int i = 1; i < n; i++) {
		if(i == n - 1 || cw(p1, pp[i], p2)) {
			while(sz(up) >= 2 && !cw(up[sz(up) - 2], up[sz(up) - 1], pp[i])) up.pop_back();
			up.pb(pp[i]);
		}
		if(i == n - 1 || ccw(p1, pp[i], p2)) {
			while(sz(down) >= 2 && !ccw(down[sz(down) - 2], down[sz(down) - 1], pp[i])) down.pop_back();
			down.pb(pp[i]);
		}
	}
	pp.clear();
	for(auto x : up) pp.pb(x);
	for(int i = sz(down) - 2; i > 0; i--) pp.pb(down[i]);
}

void input() {	
	int n;
	cin >> n;
	vector < Vector > pp(n);
	for(int i = 0; i < n; i++) cin >> pp[i].x >> pp[i].y;
	ch(pp);
	cout << sz(pp) << endl;
	for(auto x : pp) cout << x.x << ' ' << x.y << endl;
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
#ifdef LOCAL
	TIMESTAMP;
#endif	
	return 0;
}