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
const int N = 3e2+5;

int tab[N][N];
int ok, ans;

int l, c;

int main() {
  while(~scanf("%d%d", &l, &c)) {
    ok = 1;
    ans = 0;
    for(int i=0; i<l; i++) for(int j=0; j<c; j++) {
      scanf("%d", &tab[i][j]);
    }

    for(int i=0; i<l; i++) for(int j=0; j<c; j++) {
      if((tab[i][j]-1)/c != (tab[i][0]-1)/c) ok=0;
    }
    for(int j=0; j<c; j++) for(int i=0; i<l; i++) {
      if(tab[i][j]%c != tab[0][j]%c) ok = 0;
    }
    if(ok == 0) {
      printf("*\n");
      continue;
    }

    for(int i=0; i<c; i++) {
      while(i != (tab[0][i] -1 + c)%c) ans++, swap(tab[0][i], tab[0][(tab[0][i]-1+c)%c]) ;
    }
    for(int i=0; i<l; i++) {
      while(i != (tab[i][0] -1)/c) ans++,  swap(tab[i][0], tab[(tab[i][0]-1)/c][0]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
