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
const double EPS = 1e-9;

int n;
double aa[111][111];
double ans[111];
int where[111];

// returns the number of solutions
int gauss() {
	// n - number of equations
	// m - number of variables
	int m = n;
	memset(where, -1, sizeof(where));
	for(int row = 0, col = 0; col < m && row < n; col++) {
		int sel = row;
		//[PARTIAL PIVOTING]
		for(int i = row; i < n; i++) 
			if(abs(aa[i][col]) > abs(aa[sel][col]))
				sel = i;
		// if no pivot - skip this line
		// means that variable #col is independent
		if(abs(aa[sel][col]) < EPS) continue;
		// else swap two lines
		for(int i = col; i <= m; i++) swap(aa[sel][i], aa[row][i]);
		where[col] = row;
		//[/PARTIAL PIVOTING]
		//[KILL EVERYBODY IN THIS COL]
		for(int i = 0; i < n; i++) 
			if(i != row) {
				double c = aa[i][col] / aa[row][col];
				for(int j= col; j <= m; j++) 
					aa[i][j] -= aa[row][j] * c;
			}
		//[/KILL EVERYBODY IN THIS COL]
		row++;
	}
	// count ans
	for(int i = 0; i < m; i++) 
		if(where[i] != -1)
			ans[i] = aa[where[i]][n] / aa[where[i]][i];
	// check if any solution exist
	for(int i = 0; i < n; i++) {
		double sum = 0;
		for(int j = 0; j < m; j++) 
			sum += ans[j] * aa[i][j];
		if(abs(sum - aa[i][m]) > EPS) return 0;
	}
	// check if we have independent variables
	for(int i = 0; i < m; i++) if(where[i] == -1) return INF;
	return 1;
}

void input() {                  
	cin >> n;
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < n + 1; j++)
			cin >> aa[i][j];
}

void solve() {          
	assert(gauss() == 1);
	for(int i = 0; i < n; i++) 
		cout << fixed << setprecision(10) << ans[i] << ' ';
}

int main() {     
#ifdef LOCAL
	freopen("xxx.in", "r", stdin);
	freopen("xxx.out", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif	
	input();
	solve();
	return 0;
}
