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
int ans, cont;

int main() {
  char c;
  while(~scanf(" %c", &c)) {
    cont++;
    if(c == 'M') ans = 1;
    else ans++;
  }
  printf("%d\n", ans);
  for(int i=cont-ans+1; i<=cont; i++) {
    printf("%d%c", i, i==cont?'\n':' ');
  }

  return 0;
}
