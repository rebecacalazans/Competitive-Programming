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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, N = 1e5+5;

int vis[N], nt = 1, n, c[2][2], x;
vector<int> adj[2][N];
map< map<int, int>, int> t;

int weight(int g, int u, int x) {
  vis[u]=x;
  int w=1, ok=1;
  for(int i=0; i < adj[g][u].size(); i++) {
    int v=adj[g][u][i];
    if(vis[v]!=x) {
      int aux=weight(g, v, x);
      if(aux>n/2) ok=0;
      w+=aux;
    }
  }
  if(ok && (n-w)<=(n/2)) {
    if(!c[g][0]) c[g][0]=u;
    else if(!c[g][1]) c[g][1]=u;
  }
  return w;
}

int type(int g, int u, int x) {
  vis[u]=x;
  map<int, int> m;
  int size=adj[g][u].size();
  if(size==1) return 1;
  for(int i=0; i<size; i++) {
    int v=adj[g][u][i];
    if(vis[v]==x) continue;
    int aux = type(g, v, x);
    m[aux]++;
  }
  int ans= t[m]? t[m]: (t[m]=++nt);

  //db(u _ t[m]);
  return ans;
}

int main() {
  while(scanf("%d", &n) != EOF) {
    t.clear();
    memset(c, 0, sizeof(c));
    memset(vis, 0, sizeof(vis));
    x=0;
    for(int g=0; g<2; g++) for(int i=0; i<=n; i++) adj[g][i].clear();

    for(int g=0; g<2; g++) {
      for(int i=1; i<n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[g][b].push_back(a);
        adj[g][a].push_back(b);
      }
    }

    weight(0, 1, ++x);
    weight(1, 1, ++x);

    int a, b;
    a=type(0,c[0][0], ++x);
    b=type(1,c[1][0], ++x);
    if(a==b) {
      printf("S\n");
      continue;
    }
    if(c[0][1]) a=type(0,c[0][1], ++x);
    else if(c[1][1]) b=type(1,c[1][1], ++x);
    printf("%c\n", a==b? 'S':'N');
  }
  return 0;
}
