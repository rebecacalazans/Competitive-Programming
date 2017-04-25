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
const int N = 2e2;
int m, j, ans;
char a, b;
const int n = 26;

struct satstruct{

  ////////////    kosaraju    ////////////
  vi adj[N], adjr[N];
  int scc[N];
  stack<int> s;
  ////////////////////////////////////////

  satstruct() {
    /********************
    /  Modalagem:       /
    /                   /
    / a1 = a*4          /
    / ~a1 = a*4 + 1     /
    / a2 = a*4 + 2      /
    / ~a2 = a*4 + 3     /
    ********************/

    for(int i=0; i<n; i++) {
      add(4*i, 4*i+3);
    }
  }

  satstruct(satstruct s, int a, int b,  int c) {
    for(int i=0; i<4*n;  i++) {
      for(int v:s.adj[i]) adj[i].pb(v);
      for(int v:s.adjr[i]) adjr[i].pb(v);
    }
    add(a*4 + 1);
    add(a*4 + 3);
    add(b*4 + 1);
    add(b*4 + 3);
    add(c*4 + 1);
    add(c*4 + 3);

    for(int i=0; i<n; i++) {
      if (i == a || i == b || i == c) continue;
      addxor(4*i, 4*i+2);
    }
  }

  ////////////    kosaraju    ////////////
  void pos(int u) {
    scc[u] = 1;
    for(int v: adjr[u]) if(scc[v] == -1) pos(v);

    s.push(u);
  }
  void dfs(int u, int k) {
    scc[u] = k;
    for(int v: adj[u]) if(scc[v] == -1) dfs(v, k);
  }
  void kosaraju() {
    int k=0;
    cl(scc, -1);
    for(int i=0; i<4*n; i++) if(scc[i]==-1) pos(i);
    cl(scc, -1);
    while(!s.empty()) {
      int u=s.top(); s.pop();
      if(scc[u] == -1) dfs(u, ++k);
    }
  }
  ////////////////////////////////////////

  ////////////   2sat   ////////////
  void add(int a) {
    adj[a^1].pb(a);

    adjr[a].pb(a^1);
  }
  void add(int a, int b) {
    adj[a].pb(b);
    adj[b^1].pb(a^1);

    adjr[b].pb(a);
    adjr[a^1].pb(b^1);
  }
  void addor(int a, int b) {
    adj[b^1].pb(a);
    adj[a^1].pb(b);

    adjr[a^1].pb(b);
    adjr[b^1].pb(a);
  }
  void addxor(int a, int b) {
    addor(a, b);
    addor(a^1, b^1);
  }

  bool sat() {
    kosaraju();

    for(int i=0; i<4*n; i++) {
      if(scc[i] == scc[i^1]) return false;
    }
    return true;
  }
  //////////////////////////////////
};


int main() {
  scanf("%d", &m);
  satstruct s;

  for(int i=0; i<m; i++) {
    scanf(" %c%c%d%d", &a, &b, &j, &ans);
    j = j&2;
    a= (4*(a - 'A'))|j;
    b= (4*(b - 'A'))|j;

    if(ans == 0) {
      s.add(a^1);
      s.add(b^1);
    }
    else if(ans == 1) {
      s.addxor(a, b);
    }
    else if(ans == 2) {
      s.add(a);
      s.add(b);
    }
  }
  ans = 0;

  for(int i=0; i<n; i++) {
    for(int j=i+1; j<n; j++) {
      for(int k=j+1; k<n; k++) {
        satstruct aux(s, i, j, k);
        ans+=aux.sat();
      }
    }
  }
  printf("%d\n", ans);

  return 0;
}
