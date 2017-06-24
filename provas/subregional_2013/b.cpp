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

int n, m;
int p[N][4];
vector<piii> v;
set<pii> s;
int d[N], dx[N], dy[N], ok[N];
int cx[N], cy[N], c[N];

void putDest(int i, int x, int y) {
  auto it = s.upper_bound(mp(y, INF));
  if(it == s.end()) {
    d[i] = -1;
  }
  else {
    d[i] = it->nd;
  }

}

void putDest(int i, int x) {
  auto it = s.begin();

  cx[i] = x;

  if(it == s.end()) {
    c[i] = -1;
    cy[i] = -1;
  }
  else c[i] = it->nd;
}

void findDest(int i, int x, int y) {
  if(ok[i]) return;
  if(d[i] == i) return;
  if(d[i] == -1) {
    dx[i] = x;
    dy[i] = -1;
    ok[i] = 1;
    return;
  }

  findDest(d[i], dx[d[i]], dy[d[i]]);

  dx[i] = dx[d[i]] != -1? dx[d[i]]: x;
  dy[i] = dy[d[i]];
  ok[i] = 1;

}

void findDest(int i, int x) {
  if(c[i] == -1) return;

  findDest(c[i], dx[c[i]], dy[c[i]]);

  cx[i] = dx[c[i]] != -1? dx[c[i]]: x;
  cy[i] = dy[c[i]];

}

int main() {
  while(~scanf("%d%d", &n, &m)) {
    s.clear();
    v.clear();
    cl(ok, 0);
    cl(d, 0);
    cl(dx, 0);
    cl(dy, 0);
    cl(c, 0);
    cl(cx, 0);
    cl(cy, 0);
    for(int i=1; i<=n; i++) {
      scanf("%d%d%d%d", &p[i][0], &p[i][1], &p[i][2], &p[i][3]);
      if(p[i][0] > p[i][2]) swap(p[i][0], p[i][2]), swap(p[i][1], p[i][3]);

      v.pb(mp(p[i][0], mp(0, i)));
      v.pb(mp(p[i][2], mp(2, i)));
    }
    for(int i=0; i<m; i++) {
      int a;
      scanf("%d", &a);
      v.pb(mp(a, mp(1, i)));
    }

    sort(v.begin(), v.end());

    for(piii k: v) {
      int x = k.st, t = k.nd.st, i = k.nd.nd;

      if(t == 0 || t == 2) {
        if(x == p[i][0]) {
          s.insert(mp(max(p[i][1], p[i][3]), i));
          if(p[i][1] > p[i][3]) {
            putDest(i, p[i][0], p[i][1]);
            dx[i] = p[i][0];
          }
          else if(p[i][1] == p[i][3]) {
            d[i] = i;
            dx[i] = -1;
            dy[i] = p[i][1];
          }
        }
        else if(x == p[i][2]) {
          s.erase(mp(max(p[i][1], p[i][3]), i));

          if(p[i][1] < p[i][3]) {
            putDest(i, p[i][2], p[i][3]);
            dx[i] = p[i][2];
          }
        }

      }
      else if(t == 1){
        putDest(i, x);
      }
    }

    for(int i=0; i<m; i++) {
      findDest(i, cx[i]);
      printf("%d", cx[i]);
      if(cy[i] == -1) printf("\n");
      else printf(" %d\n", cy[i]);
    }
  }

  return 0;
}
