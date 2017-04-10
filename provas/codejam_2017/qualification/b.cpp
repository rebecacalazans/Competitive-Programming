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

char s[20];
int t;

int main() {
  scanf("%d",  &t);
  for(int tt=1; tt<=t; tt++) {
    printf("Case #%d: ", tt);
    scanf("%s", s);
    for(int i=1; s[i]; i++) {
      if(s[i] < s[i-1]) {
        for(int j=i; s[j]; j++) s[j] = '9';
        s[i-1]--;
        for(int j=i-1; j>0; j--) {
          if((s[j] < '0') || (s[j] < s[j-1])) s[j] = '9', s[j-1]--;
        }
      }
    }
    printf("%s\n", s[0] == '0'? s+1 :s);
  }
  return 0;
}
