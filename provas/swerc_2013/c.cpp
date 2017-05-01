#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define BUFF ios::sync_with_stdio(false);
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl		//dbs(a _ b);
#define _ << ", " <<
#define endl '\n'
#define cl(x, v) memset((x), (v), sizeof(x))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const double PI = acos(-1), EPS = 1e-9;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x3f3f3f3f, MOD = 1e9+7, N = 2e2+5;
const ld DINF = INF;

ld adj[N][N];
int n, m, q;
int f[N], nxt[N][N];
ld x[N], y[N];
char s[N];

ld dist(int a, int b) {
  ld d = sqrt((x[a] - x[b])*(x[a] - x[b]) + (y[a] - y[b])*(y[a] - y[b]) + 25.0*(f[a]-f[b])*(f[a]-f[b]));
  return d;
}

int main(){
  scanf("%d%d", &n, &m);
  double a, b;
  for(int i=0; i<n; i++) scanf("%d%lf%lf", &f[i], &a, &b), x[i] = a, y[i] = b;
  for(int i=0; i<n; i++) for(int j=0; j<n; j++) adj[i][j] = DINF;
  for(int i=0; i<n; i++) adj[i][i] = 0.0, nxt[i][i] = i;

  for(int i=0; i<m; i++) {
    int a, b;
    scanf("%d%d%s", &a, &b, s);

    if((!strcmp(s, "walking")) or (!strcmp(s, "stairs"))) {
      ld d = dist(a, b);
      if(d < adj[a][b]) adj[a][b] = d, nxt[a][b] = b;
      if(d < adj[b][a]) adj[b][a] = d, nxt[b][a] = a;
    }
    else if(!strcmp(s, "lift")) {
      if(1.0 < adj[a][b]) adj[a][b] = 1.0, nxt[a][b] = b;
      if(1.0 < adj[b][a]) adj[b][a] = 1.0, nxt[b][a] = a;
    }
    else {
      ld d = 3*dist(a, b);
      if(1.0 < adj[a][b]) adj[a][b] = 1.0, nxt[a][b] = b;
      if(d < adj[b][a]) adj[b][a] = d, nxt[b][a] = a;
    }
  }

  for(int k=0; k<n; k++)
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) {
      if(adj[i][k]+adj[k][j] < adj[i][j])
        adj[i][j] = adj[i][k] + adj[k][j],
        nxt[i][j] = nxt[i][k];
    }

  scanf("%d", &q);
  for(int i=0; i<q; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    int x = a;
    while(x != b) {
      printf("%d ", x);
      x = nxt[x][b];
    }
    printf("%d\n", b);
  }

  return 0;
}
