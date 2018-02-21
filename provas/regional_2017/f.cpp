#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n;
map<ll, map<ll, ll> > m;
map<ll, int> coord;

ll ans;

ll st[4*N];

ll query(int p, int l, int r, int i,  int j) {
  if(r < i or l > j) return 0;
  if(l >= i and r <= j) return st[p];

  return max(query(2*p, l, (l+r)/2, i, j),
             query(2*p+1, (l+r)/2+1, r, i, j));
}

void update(int p, int l, int r, int x, ll v) {

  if(r < x or l > x) return;
  if(r == x and l == x) {st[p] = max(st[p], v); return;}
  update (2*p, l, (l+r)/2, x, v);
  update (2*p+1, (l+r)/2+1, r, x, v);

  st[p] = max(st[2*p], st[2*p+1]);
}

int main() {
  scanf("%d", &n);

  for(int i=0; i<n; i++) {
    ll a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    m[a][-b] += c;
    coord[b] = 0;
  }

  int cont=0;
  for(auto& it:coord) {
    it.nd = ++cont;
  }

  for (auto& i:m) {
    for(auto& j:i.nd) {
      ll b = -j.st, c = j.nd;

      ll x = query(1, 0, cont, 0, coord[b]-1);
      update(1, 0, cont, coord[b],  x + c);
      //for(int i=1; i<=7; i++) db(st[i]);
    }
  }

  printf("%lld\n", query(1, 0, cont, 0, cont));

  return 0;
}
