#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define clear(x, y) memset(x, y, sizeof(x))

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

int o[7][6], esq[7][7], dir[7][7];
int vis[7];
int c;
int ok;

void encaixar(int p, int r, int f) {
  int aux = o[c][p];
  for(int i=0; i<7; i++) {
    if(vis[i]) continue;
    if(esq[i][o[c][p]] == r || p==5) {
      if(p==0) {
        if(dir[i][o[c][p]] == f) ok=1;
        continue;
      }
      vis[i]=1;
      encaixar(p-1, dir[i][o[c][p]], p==5? esq[i][o[c][p]]: f);
      vis[i]=0;
    }
  }
}

int main() {
  while(~scanf("%d", &o[0][0])) {
    ok=0;
    for(int i=0; i<7; i++) {
      for(int j=0; j<6; j++) if(i | j) scanf("%d", &o[i][j]);
    }
    for(int i=0; i<7; i++) {
      for(int j=0; j<6; j++) {
        esq[i][o[i][j]] = o[i][(j+5)%6];
        dir[i][o[i][j]] = o[i][(j+1)%6];
      }
    }
    for(c=0; c<7; c++) {
      vis[c]=1;
      encaixar(5, 0, 0);
      vis[c]=0;
    }
    printf("%s\n", ok? "YES":"NO");
  }
  return 0;
}
