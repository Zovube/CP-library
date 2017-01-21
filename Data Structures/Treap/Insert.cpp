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
	int x, y;
	node * l, * r;
	node() {};
	node(int a) {
		x = a;
		y = rand() | (rand() << 16);
	}
};

void input() {                  

}

void split(node * T, int key, node *& L, node *& R) {
	if(!t) L = R = 0;
	else if(key < T->key) split(T->l, key, L, T->l), R = T;
	else split(T->r, key, T->r, R), L = T;
}

void merge(node *& T, node * L, node * R) {
	if(!L || !R) T = R ? R : L;
	if(L->y > R->y) merge(L->r, L->r, R), T = L;
	else merge(R->l, L, R->l), T = R;
}

//Сначала спускаемся по дереву (как в обычном бинарном дереве поиска по k.x), но останавливаемся на первом элементе, в котором значение приоритета оказалось меньше k.y.
//Теперь вызываем split(T, k.x, T_1, T_2)от найденного элемента (от элемента вместе со всем его поддеревом)
//Полученные T_1 и T_2 записываем в качестве левого и правого сына добавляемого элемента.
//Полученное дерево ставим на место элемента, найденного в первом пункте.
void insert(node *& T, node * it) {
	if(!T) T = it;
	else if(it->y > T->y) split(T, it->x, it->l, it->r), T = it;
	else insert(it->x < T->x ? T->l : T->r, it);
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
