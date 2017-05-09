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
		l = r = 0;
	}
};

node * root = 0;
int n, x, px = 0; 
char type, ptype;

void split(node * T, int key, node *& L, node *& R) {
	if(!T) L = R = 0;
	else if(key < T->x) split(T->l, key, L, T->l), R = T;
	else split(T->r, key, T->r, R), L = T;
}

void merge(node *& T, node * L, node * R) {
	if(!L || !R) T = R ? R : L;
	else if(L->y > R->y) merge(L->r, L->r, R), T = L;
	else merge(R->l, L, R->l), T = R;
}

//Cпускаемся по дереву (как в обычном бинарном дереве поиска по it->x), но останавливаемся на первом элементе, в котором значение приоритета оказалось меньше it->y.
//Теперь вызываем split(T, it->x, T_1, T_2)от найденного элемента (от элемента вместе со всем его поддеревом)
//Полученные T_1 и T_2 записываем в качестве левого и правого сына добавляемого элемента.
//Полученное дерево ставим на место элемента, найденного в первом пункте.
void insert(node *& T, node * it) {
	if(!T) T = it;
	else if(it->y > T->y) split(T, it->x, it->l, it->r), T = it;
	else insert(it->x < T->x ? T->l : T->r, it);
}

//Спускаемся по дереву (как в обычном бинарном дереве поиска по x), и ищем удаляемый элемент.
//Найдя элемент, вызываем merge его левого и правого сыновей
//Результат процедуры merge ставим на место удаляемого элемента.
void erase(node *& T, int x) {
	if(T->x == x) merge(T, T->l, T->r);
	else erase(T->x < x ? T->l : T->r, x);
}

bool search(node * T, int x) {
    if(!T || T->x == x) return T;
    return search(T->x > x ? T->l : T->r, x);
}

int next(int x) {
	if(search(root, x)) return x;
	node * L, * R, * TT;
	split(root, x, L, R);
	if(!R) return -1;
	TT = R;
	while(TT->l) TT = TT->l;
	//very important
	// NB * 100500
	merge(root, L, R);
	return TT->x;
}

void input() {                  
	cin >> n;
}

void solve() {              
	for(int i = 0; i < n; i++) {
		cin >> type >> x;
		if(type == '+') {
			x = (x + px) % (int)(1e9);
			px = 0;
			if(search(root, x)) continue;
			node * xx = new node(x);
			insert(root, xx);
		}
		else {
			px = next(x);
			cout << px << endl;
		}
	}
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
