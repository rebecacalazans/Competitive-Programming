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

int n, q;
vi adj[N];
int pa[31][N], h[N];
ll w[31][N];

ll lca(int u, int v) {
  ll ans = 0;
  if(h[u] < h[v]) swap(u, v);

  //db(u _ h[u] _ v _ h[v]);

  for(int i=30; i>=0; i--) if(h[v] + (1<<i) <= h[u]) {
    //db(h[u] _ (1<<i) _ i _ h[v] _ pa[i][u]);
    ans += w[i][u];
    u = pa[i][u];
    //db(u);
  }
  if(u == v) return ans;
  for(int i=30; i>=0;  i--) if(pa[i][u] != pa[i][v]) {
    ans+= w[i][u] + w[i][v];
    u = pa[i][u], v = pa[i][v];
  }
  return ans + w[0][u] + w[0][v];
}

int main() {
  while(~scanf("%d", &n), n) {
    cl(w, 0);
    cl(h, INF);
    cl(pa, 0);
    pa[0][0] = 0;
    w[0][0] = 0;
    h[0] = 0;
    for(int i=1; i<n; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      pa[0][i] = a;
      w[0][i] = b;
      h[i] = h[a]+1;
      //db(i _ pa[0][i] _ w[0][i] _ h[i]);
    }

    for(int i=1; (1<<i) < n; i++) for(int j=0; j<n; j++) {
      pa[i][j] = pa[i-1][pa[i-1][j]];
      w[i][j] = w[i-1][j] + w[i-1][pa[i-1][j]];
      //db(i _ j _ pa[i][j] _ w[i][j]);
    }

    //for(int i=0; i<n; i++) printf("%d\n", h[i]);
    scanf("%d", &q);
    for(int i=0; i<q; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      printf("%lld%c", lca(a, b), i == q-1? '\n':' ');
    }
  }
  return 0;
}
