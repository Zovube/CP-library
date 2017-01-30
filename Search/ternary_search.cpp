#include <bits/stdc++.h>
#define TASK "sum"
#define fi first
#define se second
using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

const int MAXN = (int)2e6 + 22;
const ll INF = (ll)1e16;

int n;
vector < pii > gg;

double checkXY(double sx, double sy) {
	double ans = 0, x, y;
	for (int i = 0; i < n; i++) {
		x = sx - gg[i].fi;
		y = sy - gg[i].se;
		ans += sqrt(x * x + y * y);
	}
	return ans;
}

double checkX(double x) {
	double l = -MAXN, r = MAXN, m1, m2, v1, v2;
	for (int i = 0; i < 120; i++) {
		m1 = l + (r - l) / 3;
		m2 = r - (r - l) / 3;
		v1 = checkXY(x, m1);
		v2 = checkXY(x, m2);
		if (v1 < v2) {
			r = m2;
		} else {
			l = m1;
		}
	}
	return l;
}

void srch() {
	double l = -MAXN, r = MAXN, m1, m2, v1, v2;
	for (int i = 0; i < 120; i++) {
		m1 = l + (r - l) / 3;
		m2 = r - (r - l) / 3;
		v1 = checkXY(m1, checkX(m1));
		v2 = checkXY(m2, checkX(m2));
		if (v1 < v2) {
			r = m2;
		} else {
			l = m1;
		}
	}
	cout << fixed << setprecision(30);
	cout << l << " " << checkX(l) << "\n";
}

void solve() {
	cin >> n;
	gg.resize(n);
	for (int i = 0; i < n; i++)
		cin >> gg[i].fi >> gg[i].se;
	srch();		
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
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
		solve();
	return 0;
}
