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

int n;
vi adj[N], ans;
char grid[N][N];
int vis[N];

void dfs(int u) {
  if(vis[u]) return;
  vis[u] = 1;

  for(int v:adj[u]) dfs(v);

  ans.pb(u);
}

int main() {
  scanf("%d", &n);
  for(int i=0; i<n; i++) scanf("%s", grid[i]);

  for(int i=0; i<n; i++) for(int j=0;  j<n; j++)
    if(grid[i][j] == '1') adj[i].pb(j);

  dfs(0);

  if(ans.size() == n)
    for(int v:ans) printf("%d ", v);
  else printf("impossible");
  printf("\n");

  return 0;
}
