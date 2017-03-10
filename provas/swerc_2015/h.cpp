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

ll x, y, aux, aa, ans;
int a, b, cont;

int main() {
  scanf("%lld%lld", &x, &y);
  for(int a=1; a<=63; a++) {
    aa=0;
    for(int i=0; i<a; i++) aa= (aa<<1)+1;
    if(aa>=x && aa <= y) ans++;

    for(int b=1; b<=63; b++) {
      cont = a;
      aux = aa;
      while(1) {
        aux<<=b;
        cont+=b;
        if(cont>63) break;
        if(aux>=x && aux <= y) ans++;

        aux<<=a;
        aux+=aa;
        cont+=a;
        if(cont>63) break;
        if(aux>=x && aux <= y) ans++;
      }
    }
  }

  printf("%lld\n", ans);
  return 0;
}
