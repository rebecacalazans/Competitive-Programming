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
const int N = 1e3+5;

int n, m, k, s, t;
vector<piii> adj[N];
int cnt, ans;
vi cmp, ok;
int vis[N];

bool dfs(int u, int x) {
  if(u == t) return true;
  //db(u);
  vis[u] = cnt;
  for(auto p: adj[u]) {
    int v = p.st;
    if(vis[v] == cnt) continue;
    if(p.nd.st > x or p.nd.nd < x) continue;
    //db(u _ v _ p.nd.st _ p.nd.nd);
    if(dfs(v, x)) return true;
  }
  return false;
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  scanf("%d%d", &s, &t);

  cmp.pb(1);
  cmp.pb(k);
  for(int i = 1; i <= m; i++) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);

    adj[a].pb({b, {c,d}});
    cmp.pb(c);
    cmp.pb(c-1);
    cmp.pb(d);
    cmp.pb(d+1);
  }

  sort(cmp.begin(), cmp.end());
  cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());

  for(int x: cmp) {
    //db(x);
    ++cnt;
    if(dfs(s, x)) ans++, ok.pb(1);
    else ok.pb(0);
  }

  //for(int i = 0; i < cmp.size(); i++) db(i _ cmp[i] _ ok[i]);

  for(int i = 1; i < cmp.size(); i++) {
    if(ok[i] and ok[i-1]) ans += cmp[i] - cmp[i-1] - 1;
  }

  printf("%d\n", ans);

  return 0;
}
