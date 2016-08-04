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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, N = 2e3+5;

int dp[N];
int v[10];
int t, ma;
long long tot;

int func1(int val) {
  if(val == 0) return 0;
  if(dp[val]) return dp[val];
  dp[val] = val;
  for(int i = 0; i<6; i++) {
    if(v[i]>val) break;
    dp[val] = min(dp[val], 1+func1(val-v[i]));
  }
  return dp[val];
}

int func2(int val) {
  int ans = func1(val);
  for(int i=val; i<2000; i++) {
    ans = min(ans, func1(i)+func1(i-val));
  }
  return ans;
}

int main() {
  scanf("%d", &t);
  for(int tt = 0; tt<t; tt++) {
    tot = ma = 0;
    cl(dp, 0);
    for(int i=0; i<6; i++) scanf("%d", &v[i]);

    for(int i=1; i<=100; i++) {
      int a = func2(i);
      ma = max(ma, a);
      tot+=a;
    }
    printf("%lld.%.2lld %d\n", tot/100, tot%100, ma);
  }
  return 0;
}
