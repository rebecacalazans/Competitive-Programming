#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7, N = 1e7+5;
int p[N];
vector<int> primes;
ll n;

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
  while(scanf("%lld", &n)!=EOF) {
    printf("%lld\n", phi(n)/2);
  };
  return 0;
}
