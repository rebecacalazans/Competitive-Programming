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

int t;
ll k, n;

int main() {

  scanf("%d", &t);
  for(int tt=1; tt<=t; tt++) {
    printf("Case #%d: ", tt);
    map<ll,ll> m;
    map<ll, ll>::iterator it;

    scanf("%lld%lld", &n, &k);
    m[n]++;
    while(k) {
      it = m.end();
      it--;
      ll size=it->st, qnt=it->nd;
      if(k > qnt) {
        k-=qnt;

        m[size/2]+=qnt;
        m[(size-1)/2]+=qnt;

        m.erase(size);
      }
      else {
        m[size] -= k;
        k=0;
      }
    }

    it = m.end();
    it--;
    ll size=it->st;

    printf("%lld %lld\n", size/2, (size-1)/2);
  }
  return 0;
}
