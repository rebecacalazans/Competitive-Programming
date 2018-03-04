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
const int N = 1e2+5;

int p, q;
int grid[N][N];
int dp[N][N];

int ma(int i, int j) {
  if(i == 0 or j == 0) return dp[i][j] = 0;
  if(dp[i][j] != INF) return dp[i][j];
  int ans = -INF;

  //int l;


  for(int k=0; k<j; k++) {
    int aux = grid[i][j] - grid[i][k];
    aux -= ma(k, i);
    //if(aux > ans) l = k, db(i _ j _ k _ grid[i][j] _ grid[i][k]);
    ans = max(ans, aux);
  }
  //db(i _ j _ ans _ l);
  return dp[i][j] = ans;
}

int main() {
  scanf("%d%d", &p, &q);


  int x = max(p, q);

  grid[1][1] = (q%2)?1:-1;
  for(int i=2; i<=x; i++) grid[i][1] = -grid[i-1][1];
  for(int i=1; i<=x; i++) for(int j=2; j<=x; j++) grid[i][j] = -grid[i][j-1];

  /*
  for(int i=0; i<=p; i++) {
    for(int j=0; j<=q; j++) {
      printf("%2d ", grid[i][j]);
    }
    printf("\n");
  }
  */

  for(int i=1; i<=x; i++) for(int j=1; j<=x; j++) {
    grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
  }

  /*
  for(int i=0; i<=p; i++) {
    for(int j=0; j<=q; j++) {
      printf("%2d ", grid[i][j]);
    }
    printf("\n");
  }
  */

  cl(dp, 0x3f);

  //db(p _ q);
  printf("%d\n", ma(p, q));

  /*
  for(int i=1; i<=x; i++) {
    for(int j=1; j<=x; j++) {
      printf("%2d ", dp[i][j]==INF?0:dp[i][j]);
    }
    printf("\n");
  }
  */

  return 0;
}
