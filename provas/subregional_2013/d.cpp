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
const int N = 1e6+5;

set<vi> s;
int vis[N];
int n, m;
vi v, f, masks;

void showmask(int m) {
  for(int i=0; i<=15; i++)
    if(m & (1<<i)) printf("1");
    else printf("0");
  printf("\n");
}


void fold(vi v, vi masks, int mask, int pos) {
  //showmask(mask);
  vi vaux, masksaux;
  int ok1 = 1, ok2 = 1;

  if(vis[mask]) return;
  vis[mask] = 1;

  for(int i=0; ok1 or ok2; i++) {
    int m = 0;
    ok1 = ok2 = 0;
    if(pos-i >= 0) m |= masks[pos-i], ok1 = 1;
    if(pos+i < masks.size()) m |= masks[pos+i], ok1 = 1;
    if(ok1) masksaux.pb(m);

    m = 0;
    if(pos-i-1 >= 0) m += v[pos-i-1], ok2 = 1;
    if(pos+i < v.size()) m+= v[pos+i], ok2 = 1;
    if(ok2) vaux.pb(m);
  }
  s.insert(vaux);
  /*
  for(int u: vaux) {
    db(u);
  }

  for(int u: masksaux) {
    showmask(u);
  }
  getchar();
  */

  for(int i=1; i<masksaux.size()-1;  i++) {
    int m = mask|masksaux[i];
    if(!vis[m]) fold(vaux, masksaux, mask|masksaux[i], i);
  }
}

void invf() {
  int i = 0, j = f.size()-1;
  for(; i<j; i++, j--) {
    swap(f[i], f[j]);
  }
}

int main() {
  while(~scanf("%d", &n)) {
    cl(vis, 0);
    s.clear();
    f.clear();
    v.clear();
    masks.clear();
    for(int i=0; i<n; i++) {
      int aux;
      scanf("%d", &aux);
      v.pb(aux);
      masks.pb(1<<i);
    }
    masks.pb(1<<n);
    scanf("%d", &m);
    for(int i=0; i<m; i++) {
      int aux;
      scanf("%d", &aux);
      f.pb(aux);
    }
    s.insert(v);
    //int m = masks[0]|masks[n]|masks[3];
    //if(!vis[m]) fold(v, masks, m, 3);

    for(int i=1; i<n; i++) {
      //db(i);
      int m = masks[0]|masks[n]|masks[i];
      if(!vis[m]) fold(v, masks, m, i);
    }

    if(s.find(f) != s.end()) {
      printf("S\n");
      continue;
    }
    invf();
    if(s.find(f) != s.end()) {
      printf("S\n");
      continue;
    }
    printf("N\n");

  }
  return 0;
}
