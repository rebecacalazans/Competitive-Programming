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
const int N = 4e3+5;

int n, m;
int vis[N];
int ok[N];
int x;
int alc[N][N];

vi adj[N];

void dfs(int u, int v) {
  vis[u] = x;
  alc[v][u] = 1;

  for(int w: adj[u]) if(vis[w] != x) dfs(w, v);
}

int main() {
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    if(a > b) swap(a, b);

    if(b < 0) {
      a = -a;
      b = -b;
      adj[2*a].pb(2*b+1);
      adj[2*b].pb(2*a+1);
    }
    else if(a < 0) {
      a = -a;
      adj[2*a].pb(2*b);
      adj[2*b+1].pb(2*a+1);
    }
    else {
      adj[2*a+1].pb(2*b);
      adj[2*b+1].pb(2*a);
    }
  }

  for(int i = 1; i <= n; i++) {
    x++; dfs(2*i, 2*i);
    x++; dfs(2*i+1, 2*i+1);
  }

  for(int i = 1; i <= n; i++) {
    if(alc[2*i][2*i+1] and alc[2*i+1][2*i]) {
      printf("0\n");
      return 0;
    }
  }

  for(int i = 1; i <= n; i++) {
    if(alc[2*i][2*i+1]) {
      printf("1\n");
      return 0;
    }
  }

  for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) {
    if(alc[2*i][2*j+1]) {
      printf("2\n");
      return 0;
    }
  }


  printf("-1\n");

  return 0;
}
