#pragma GCC optimize("O3") 
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx") 
#define __USE_MINGW_ANSI_STDIO 0
#include<bits/stdc++.h>                               
using namespace std;

#define PI acos(-1)
#define pb push_back
#define fi first
#define se second
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
	
const int MAXN = 5e2 + 9;
const int MOD = (int)(1e9 + 7);
const int LOG2MAXN = 17;
const int INF = 1e9;
const ld eps = 1e-9;

int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
char ddir[] = {'R', 'U', 'L', 'D'};

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

struct cd {
	double real, imag;
	
	cd() {}
	cd(double _real, double _imag) : real(_real), imag(_imag) {}
	
	void operator/= (const int k) { real /= k, imag /= k; }
	cd operator* (const cd & a) { return cd((real * a.real - imag * a.imag), (real * a.imag + imag * a.real)); }
	cd operator- (const cd & a) { return cd((real - a.real), (imag - a.imag)); }
	cd operator+ (const cd & a) { return cd((real + a.real), (imag + a.imag)); }
};


const int LOG = 20;
const int N = 1 << LOG;
cd A[N], B[N], C[N], F[2][N], w[N];
int rev[N];
	
void initFFT() {
	double alp;
	for(int i = 0; i < N; i++) {
		alp = (2 * PI * i) / N;
		w[i] = cd(cos(alp), sin(alp));
	}
	int k = 0;
	for(int mask = 1; mask < N; mask++) {
		if(mask == (1 << (k + 1))) k++;
		rev[mask] = rev[mask ^ (1 << k)] ^ (1 << (LOG - 1 - k));
	}	
}

void FFT(cd * A, int k) {
	int L = 1 << k;
	for(int mask = 0; mask < L; mask++) F[0][rev[mask] >> (LOG - k)] = A[mask];
	int t = 0, nt = 1;
	for(int lvl = 0; lvl < k; lvl++) {
		int len = 1 << lvl;
		for(int st = 0; st < L; st += (len << 1)) {
			for(int i = 0; i < len; i++) {
				cd add = F[t][st + len + i] * w[(i << (LOG - 1 - lvl))];
				F[nt][st + i] = F[t][st + i] + add;
				F[nt][st + len + i] = F[t][st + i] - add;
			}
		}
		swap(t, nt);	
	}
	for(int i = 0; i < L; i++) A[i] = F[t][i];
}
	
void invFFT(cd * A, int k) {
	FFT(A, k);
	for(int i = 0; i < (1 << k); i++) A[i] /= (1 << k);
	reverse(A + 1, A + (1 << k));
}

void input() {
	int n;
	cin >> n;
	int k = 0;
	while((1 << k) < 2 * n + 1) k++;
	for(int i = 0; i < n + 1; i++) cin >> A[n - i].real;
	for(int i = 0; i < n + 1; i++) cin >> B[n - i].real;
	FFT(A, k);
	FFT(B, k);
	for(int i = 0; i < (1 << k); i++) C[i] = A[i] * B[i];
	invFFT(C, k);
	for(int i = 2 * n; i >= 0; i--) cout << (ll)(round(C[i].real)) << ' ';
	cout << "\n";
	for(int i = 0; i < (1 << k); i++) {
		A[i] = cd(0, 0);
		B[i] = cd(0, 0);
		C[i] = cd(0, 0);
	}
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
	initFFT();
	int tt;
	cin >> tt;
	while(tt--) {
		input();
	}
#ifdef LOCAL
	TIMESTAMP;
#endif	
	return 0;
}