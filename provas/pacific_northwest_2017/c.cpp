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

ll a, b;

ll sum;

int main() {
  scanf("%lld%lld", &a, &b);

  for(ll i = 1; i < N; i++) {
    sum += i * ((b/i) - ((a-1)/i)); 
  }

  for(ll i = 1; i < N; i++) {
    ll auxb = (b/i),
       auxa = (a+i-1)/i;

    if(auxb < N) break;
    if(auxa < N) auxa = N;
    sum += ((auxb - auxa + 1)*(auxb + auxa))/2;
  }

  printf("%lld\n", sum);

  return 0;
}
