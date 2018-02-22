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

int m, k, n, ans;
map<pii, int> c;
map<int, int> cont;

void update(int x, int l, int r) {
  //for(auto it: cont) db(it.st _ it.nd);
  assert(l <= r);

  auto it = c.upper_bound(mp(l, INF));
  assert(it != c.begin());
  it--;
  pair<int, int> p = it->st;

  while(it != c.end()) {
    if(p.st > r) break;

    if(p.st < l) {
      cont[it->nd] += l - p.st;
      c[mp(p.st, l-1)] = it->nd;
      assert(p.st <= l-1);
    }

    if(p.nd > r) {
      cont[it->nd] += p.nd - r;
      c[mp(r+1, p.nd)] = it->nd;
      assert(r+1 <= p.nd);
    }

    cont[it->nd] -= p.nd-p.st+1;
    c.erase(p);

    it = c.upper_bound(mp(l, INF));
    p = it->st;
  }

  cont[x] += r-l+1;
  c[mp(l, r)] = x;
}


int main() {
  scanf("%d%d%d", &m, &k, &n);
  c[mp(0, m-1)] = 1;
  cont[1] = m;

  for(int i=0; i<n; i++) {
    int p, x;
    ll a, b;
    scanf("%d%d%lld%lld", &p, &x, &a, &b);
    ll s = cont[p];
    ll k1 = (a+s*s)%m, k2 = (a+(s+b)*(s+b))%m;
    //db(k1 _ k2 _ x);
    update(x, min(k1, k2), max(k1, k2));

    /*
    for(auto it: c) db(it.st.st _ it.st.nd _ it.nd);
    for(int i=1; i<=k; i++) db(i _ cont[i]);
    */
  }

  for(auto p:cont) {
    ans = max(p.nd, ans);
  }

  printf("%d\n", ans);

  return 0;
}
