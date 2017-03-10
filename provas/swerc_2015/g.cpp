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

int n, p, k, c;
int m;
int cards[1005], grundy[1005], aux[21];
int ans;

int main() {
  scanf("%d%d", &p, &k);
  for(int i=0; i<p; i++) {
    scanf("%d", &m);
    for(int j=1; j<=m; j++) scanf("%d", &cards[j]);

    for(int j=1; j<=m; j++) {
      cl(aux, 0);
      for(int x=0; x<=k; x++) {
        int tmp = j-x;
        if(tmp <= 0) continue;
        tmp -= cards[tmp];
        if(tmp >= 0) aux[grundy[tmp]] = 1;
      }
      for(int x=0;; x++) if(!aux[x]) {
        grundy[j] = x;
        break;
      }
    }
    if(i == 0) ans = grundy[m];
    else ans ^= grundy[m];
  }

  printf("%s\n", ans?"Alice can win." :"Bob will win.");

  return 0;
}
