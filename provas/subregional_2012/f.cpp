#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7, N = 1e2+5;

int n, a, b, c, vis[N], db, dc;
vector<int> adj[N];

int bfs(int u, int d) {
  vis[u]=1;
  if(u==b) db=d, vis[u]=2;
  if(u==c) dc=d, vis[u]=3;
  for(int i=0; i<adj[u].size(); i++) {
    int v=adj[u][i], aux;
    if(!vis[v]) {
      aux=bfs(v, d+1);
      if((aux==3&&vis[u]==2) || (aux==2&&vis[u]==3)) a=u, db-=d, dc-=d;
      if(vis[u]==1)
        vis[u]=aux;
    }
  }
  return vis[u];
}

int main() {
  while (~scanf("%d%d%d%d", &n, &a, &b, &c)) {
    db=dc=0;
    for(int i=1; i<=n; i++) adj[i].clear();
    memset(vis, 0, sizeof(vis));
    for(int i=1; i<n; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    bfs(a, 0);
    ld r=((ld)dc)/(dc+db);
    printf("%.6Lf\n", r);
  }
  return 0;
}
