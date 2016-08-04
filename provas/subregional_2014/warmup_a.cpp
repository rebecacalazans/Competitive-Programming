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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, N = 1e5+5;

int v[N];
int n, r, ma;

int main() {
  while(scanf("%d%d", &n, &r), n|r) {
    ma = 0;
    cl(v, 0);
    for(int i=0; i<r; i++) {
      scanf("%d", &v[i]);
    }
    int i, j;
    for(i=0, j=0; i<r;) {
      if(v[i]-v[j]+1 <= n) {
        ma = max(ma, i-j+1);
        i++;
      }
      else {
        j++;
      }
    }
    printf("%d\n", n-ma);
  }
  return 0;
}
