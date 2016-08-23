#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, y) memset(x, y, sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7, N = 105;

char tab[N][N];
int h[N][N];
int n, cont, ans, x;
vi adj[N*N];
int b[N*N], vis[N*N];

bool match(int u) {
  if(vis[u]==x) return 0;
  vis[u] = x;
  for(int v:adj[u]) {
    if(!b[v] or match(b[v])) return b[v] = u;
  }
  return 0;
}

int main() {
  while(~scanf("%d", &n)) {
    ans = x = 0;
    cl(h, 0);
    cl(vis, 0);
    cl(b, 0);
    for(int i=0; i<=n*n; i++) adj[i].clear();

    for(int i=0; i<n; i++) scanf("%s", tab[i]);

    cont = 0;
    for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
        while(j<n and tab[i][j] == 'X') h[i][j] = 0, j++;
        cont++;
        while(j<n and tab[i][j] == '.') {
          h[i][j] = cont; j++;
        }
      }
    }

    cont = 0;
    for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
        while(j<n and tab[j][i] == 'X') j++;
        cont++;
        while(j<n and tab[j][i] == '.') adj[cont].pb(h[j][i]), j++;
      }
    }

    for(int i=1; i<=cont; i++) x++, ans += match(i);
    printf("%d\n", ans);

  }
  return 0;
}
