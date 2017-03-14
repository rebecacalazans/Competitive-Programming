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
const int N = 5e3+5;

int a, b, e, p;
int pa[N], ch[N];
int vis[N];
vi adj[N];
int ans[3];

void go(int u, int x) {
  if(vis[u] == x) return;
  vis[u] = x;

  if(u != x) {
    pa[u]++;
    ch[x]++;
  }

  for(int v:adj[u]) {
    go(v, x);
  }
}

int main() {
  cl(vis, -1);
  scanf("%d%d%d%d", &a, &b, &e, &p);

  for(int i=0; i<p; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    adj[x].pb(y);
  }

  for(int i=0; i<e; i++) go(i, i);

  for(int i=0; i<e; i++) {
    if(e-ch[i] <= a) ans[0]++;
    if(e-ch[i] <= b) ans[1]++;
    if(pa[i] >= b) ans[2]++;
  }
  for(int i=0; i<3; i++)
    printf("%d\n", ans[i]);
  return 0;
}
