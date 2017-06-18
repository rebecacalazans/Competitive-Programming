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
const int INF = 0x3f3f3f3f, MOD = 1e6;
const int N = 1e5+5;
ll n, k, l;


struct m22{
  ll a, b, c, d;
  m22(ll a, ll b, ll c, ll d):a(a), b(b), c(c), d(d){}
  m22 operator*(m22 m) {return m22((a*m.a+b*m.c)%MOD, (a*m.b+b*m.d)%MOD,
                                   (c*m.a+d*m.c)%MOD, (c*m.b+d*m.d)%MOD);}
};

m22 fastexp(m22 x, ll b) {
  m22 ans(1, 0, 0 , 1);
  while(b) {
    if(b%2) ans = ans*x;
    b/=2;
    x = x*x;
  }
  return ans;
}

int main() {
  while(~scanf("%lld%lld%lld", &n, &k, &l)) {
    k%=MOD;
    l%=MOD;
    n/= 5;
    if (n == 1) {
      printf("%06lld\n", k);
      continue;
    }
    if (n == 2) {
      printf("%06lld\n", ((k*k)%MOD + l)%MOD);
      continue;
    }
    m22 m(k,l, 1, 0);
    m = fastexp(m, n-2);
    printf("%06lld\n", ((m.a*((k*k)%MOD + l))%MOD + m.b*k)%MOD);
  }
  return 0;
}
