#include<bits/stdc++.h>                               
using namespace std;

#define PI acos(-1)
#define fi first
#define se second
#define pb push_back
#define sz(a) (int)(a).size()
#define all(c) (c).begin(), (c).end()
#define TIMESTAMP fprintf(stdout, "Execution time: %.3lf s.\n", (double)clock()/CLOCKS_PER_SEC)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair <int, int> pii;
typedef vector <vi> vvi;
typedef vector <pii> vpii;
typedef vector<string> vs;

const int INF = 100500;
const int MAXN = 5e4 + 9;
const int MOD = 1e9 + 7;

struct node {
	int key, prior, num;
	node * l, * r, * p;
	node() {}
	node(int k, int p, int x) : key(k), prior(p), num(x), l(0), r(0) {}
};

typedef node * pnode;

int n, a, b;

struct ans {
	int a, b, c;
	ans() {};
} ans[MAXN];

struct  ttt {
	int a, b, c;
	ttt() {};
};

ttt answer[MAXN];

pnode root = 0;
pnode lleft = 0;

pnode insert(pnode * root, int a, int b, int c) {
	pnode new_right = new node(a, b, c);
	// to keep heap properties we are going up while prior of current node is less than added prior
	while(lleft != *root && lleft->prior < new_right->prior) lleft = lleft->p;
	// if find found such node
	// added left son is current right son
	// and current right son is added
	if(lleft && lleft->prior >= b) {
		new_right->l = lleft->r;
		if(lleft->r) lleft->r->p = new_right;
		lleft->r = new_right;
		new_right->p = lleft;
	}
	// else added is root
	// and root is added left son
	else {
		new_right->l = *root;
        if(*root) (*root)->p = new_right;
        *root = new_right;
	}
	return new_right;
}

inline void go(pnode v) {
	if(v) {
		go(v->l);
		ans[v->num].a = (v->p ? v->p->num : 0);
		ans[v->num].b = (v->l ? v->l->num : 0);
		ans[v->num].c = (v->r ? v->r->num : 0);
		go(v->r);
	}
}

bool cmp(ttt t, ttt tt) {
	if(t.a < tt.a) return 1;
	if(t.a > tt.a) return 0;
	return 0;
}

void input() {                  
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> answer[i].a >> answer[i].b;
		answer[i].c = i + 1;
	}
	sort(answer, answer + n, cmp);
	for(int i = 0; i < n; i++) {
		// lleft is in fact most current right
		// beause of sorting we now that next will have greater key
		lleft = insert(&root, answer[i].a, answer[i].b, answer[i].c);
	}
	cout << "YES" << endl;
	go(root);
	for(int i = 1; i <= n; i++)
		cout << ans[i].a << ' ' << ans[i].b << ' ' << ans[i].c << endl; 
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
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
#endif	
	input();
	solve();
	return 0;
}
