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

char s[N];
int cont[N];
int n;
ll ans;

int gcd(int a, int b) {return b?gcd(b, a%b):a;}

int test(int x) {
  for(int i=0; i<x; i++) {
    if(s[i] == 'P') continue;
    int ok=1;
    for(int j=(i+x)%n; j!=i; j=(j+x)%n) if(s[j] == 'P') {
      ok=0;
      break;
    }
    if(ok) {
      cont[x] = 1;
      return 0;
    }
  }
}

int main() {
  scanf("%s", s);
  n = strlen(s);

  for(int i=1; i<n; i++) {
    int x = gcd(n, i);
    if(x == i) test(x);
    ans += cont[x];
  }

  printf("%lld\n", ans);

  return 0;
}
