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

struct node {
	int val, depth;
	node * l, * r, * p;
	node() {}
	node(int t) : val(t), depth(0), l(0), r(0), p(0) {}

	node * operator = (const node * x) {
		val = x->val;
		l = x->l;
		r = x->r;
		p = x->p;
	}
};

typedef node * pnode;
pnode root = new node(0);

//print sorted values
void Inorder_Tree_Walk(pnode x) {
	if(x) {
		Inorder_Tree_Walk(x->l);
		cout << x->val << '\n';
		Inorder_Tree_Walk(x->r);
	}
}

//find value
pnode Tree_Search(pnode x, int k) {
	if(!x || x->val == k) return x;
	if(k < x->val) return Tree_Search(x->l, k);
	else return Tree_Search(x->r, k);
}

//must be faster than recursive version
pnode Iterative_Tree_Search(pnode x, int k) {
	while(x && k != x->val) {
		if(x->val > k) x = x->l;
		else x = x->r;
	}
	return x;
}

//find minimum
pnode Tree_Minimum(pnode x) {
	while(x->l) x = x->l;
	return x;
}

//find minimum
pnode Tree_Maximum(pnode x) {
	while(x->r) x = x->r;
	return x;
}

//find next in sorted order
pnode Tree_Successor(pnode x) {
	if(x->r) return Tree_Minimum(x->r);
	pnode y = x->p;
	while(y && x == y->r) {
		x = y;
		y = y->p;
	}
	return y;
}

//find previous in sorted order
pnode Tree_Predecessor(pnode x) {
	if(x->l) return Tree_Maximum(x->l);
	pnode y = x->p;
	while(y && x == y->l) {
		x = y;
		y = y->p;
	}
	return y;
}

//insert element
void Tree_Insert(pnode z) {
	pnode y = new node(0);
	pnode x = root;
	while(x) {
		y = x;
		if(z->val < x->val) x = x->l;
		else x = x->r;
	}
	z->p = y;
	if(!y) root = z;
	else if(z->val < y->val) y->l = z;
	else y->r = z;
}

//change subtrees of u and v
void Transplant(pnode u, pnode v) {
	if(!u->p) root = v;
	else if(u == u->p->l) u->p->l = v;
	else u->p->r = v;
	if(v) v->p = u->p;
}

//delete element
void Tree_Delete(pnode z) {
	if(!z->l) Transplant(z, z->r);
	else if(!z->r) Transplant(z, z->l);
	else {
		pnode y = Tree_Minimum(z->l);
		if(y->p != z) {
			Transplant(y, y->r);
			y->r = z->r;
			y->r->p = y;
		}
		Transplant(z, y);
		y->l = z->l;
		y->l->p = y;
	}
}

void input() {
	
}

void solve() {          

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
