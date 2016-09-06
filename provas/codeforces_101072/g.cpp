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
int n;
ll v[20], fat[20];
ll dp[1<<20];

int main() {
  scanf("%d", &n);
  for(int i=0; i<n; i++) scanf("%lld", &v[i]);
  sort(v, v+n);
  fat[0] = 1;
  for(int i=1; i<20; i++) fat[i] = i*fat[i-1];

  for(int i=1; i<(1<<n); i++) {
    for(int j=0; j<20; j++) if((1<<j) & i) {
      int c=0, e=0, d=0;
      dp[i]+=dp[i-(1<<j)];

      for(int k=0; k<20; k++) if((1<<k) & i){
        c++;
        if(v[k] < v[j]) e++;
        if(v[k] > v[j]) d++;
      }
      dp[i] += fat[c-1]*min(e, d);
    }
  }
  printf("%.9f\n", ((double) dp[(1<<n)-1])/fat[n]);



  return 0;
}
