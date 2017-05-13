#pragma GCC optimize("O3") 
#define TASK ""
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
#define TIMESTAMP fprintf(stderr, "MYSTACK  Execution time: %.3lf s.\n", (double)clock()/CLOCKS_PER_SEC)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair <int, int> pii;
typedef vector <vi> vvi;
typedef vector <pii> vpii;
typedef vector<string> vs;

const int MAXN = 2e5 + 9;
const int MOD = (int)(1e9 + 7);
const int INF = 100500;

int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
int n, m;

struct my_stack {
	int cnt;
	vi el;
	
	my_stack() {
		cnt = 0;
		el.resize(MAXN);
	}
	
	void push(int x) {
		if(cnt == sz(el)) {
			el.resize(2 * cnt);
		}
		el[cnt++] = x;
	}
	
	int pop() {
		return el[--cnt];
	}
	
	int back() {
		return el[cnt - 1];
	}
	
	bool empty() {
		return !cnt;
	}
} st;

void input() {
	string s;
	int x;
	while(cin >> s) {
		if(s == "push") {
			cin >> x;
			st.push(x);
			cout << "ok\n";
		}
		if(s == "pop") {
			if(st.empty()) {
				cout << "error\n";
			}
			else {
				cout << st.pop() << "\n";
			}		
		}
		if(s == "size") {
			cout << st.cnt << "\n";
		}
		if(s == "back") {
			if(st.empty()) {
				cout << "error\n";
			}
			else {
				cout << st.back() << "\n";
			}
		}
		if(s == "clear") {
			st.cnt = 0;
			cout << "ok\n";
		}
		if(s == "exit") {
			cout << "bye\n";
			exit(0);
		}					
	}
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
	//freopen(TASK".in", "r", stdin);
	//freopen(TASK".out", "w", stdout);
#endif	
	input();
	solve();
	TIMESTAMP;
	return 0;
}