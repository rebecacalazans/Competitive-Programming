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

ll n, e, c, m, d, ph, phn;
int p[N];
vector<int> primes;

ll fastexp(ll a, ll b, ll mod) {
  ll ans = 1;
  while(b) {
    if(b%2) ans = (ans*a)%mod;
    b/=2;
    a = (a*a)%mod;
  }
  return ans;
}

void calcprimes() {
  for(ll i=2; i<N; i++) {
    if(!p[i]){
      primes.push_back(i);
      for(ll j=i*i; j<N; j+=i) p[j]=1;
    }
  }
}

ll phi(ll n) {
  ll ind=0, pf=primes[0], ans=n;

  while(pf*pf<=n) {
    if(n%pf==0) ans-=ans/pf;
    while(n%pf==0)n/=pf;
    pf=primes[++ind];
  }
  if(n!=1) ans-=ans/n;
  return ans;
}

int main() {
  calcprimes();

  scanf("%lld%lld%lld", &n, &e, &c);
  phn = phi(n);
  ph = phi(phn);
  d = fastexp(e, ph-1, phn);

  m = fastexp(c, d, n);

  printf("%lld\n", m);

  return 0;
}
