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
const int N = 1e3+5;

int n, m;
char s[N];
char dp[N][N];
int d[N];

int main() {
  scanf("%s%d", s, &m);
  n = strlen(s);

  d[n-1] = 1;
  for(int i = n-2; i >= 0; i--) d[i] = (d[i+1]*10)%m;
  dp[n][0] = '\n';

  for(int i=n-1; i>=0; i--) {
    for(int j=0; j<m; j++) {
      if(s[i] == '?') {
        for(int k=0; k<10; k++) {
          if(i == 0 and k==0) continue;
          int x = (d[i]*k)%m;
          x = (m + j - x)%m;
          if(dp[i+1][x]) {
            dp[i][j] = k+'0';
            break;
          }
        }
      }
      else {
        int x = (d[i]*(s[i]-'0'))%m;
        x = (m + j - x)%m;
        if(dp[i+1][x]) {
          dp[i][j] = s[i];
        }
      }
    }
  }

  /*
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      printf("%c  ", dp[i][j]?dp[i][j]:'-');
    }
    printf("\n");
  }
  */

  if(dp[0][0]) {
    for(int i=0, x=0; s[i]; i++) {
      printf("%c", dp[i][x]);
      x = (m + x - ((dp[i][x]-'0')*d[i])%m)%m;
    }
    printf("\n");
  }
  else {
    printf("*\n");
  }

  return 0;
}
