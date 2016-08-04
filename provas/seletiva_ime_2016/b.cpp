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
char s[N];
int cont;

int main() {
  while(~scanf("%s", s)) {
    cont=0;
    int n=strlen(s);
    for(int i=n-1; i>=0; i--) {
      if(s[i]=='1' && cont<2) {
        cont=0;
        break;
      }
      if(s[i]=='1') cont--;
      else cont++;
    }
    printf("%d\n", cont);
  }
  return 0;
}
