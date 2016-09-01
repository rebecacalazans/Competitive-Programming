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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, N = 1e5+5;
int n, k;
ll v[N];
ll dp[N];

int main() {
  while(scanf("%d", &n)!= EOF) {
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<=n; i++) scanf("%lld", &v[i]), v[i]+=v[i-1];

    for(k=1; k<=n; k++) {
      for(int i=1; i<=n-k+1; i++) {
        if(k==1) {
          dp[i]=v[i]-v[i-1];
          continue;
        }
        dp[i]=v[i+k-1]-v[i-1]-min(dp[i], dp[i+1]);
      }
    }
    printf("%lld\n", dp[1]);
  }
  return 0;
}
