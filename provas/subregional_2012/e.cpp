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
const int N = 20;

ll n, k;
ll tk[N], t0[N][N], t1[N][N], t3[N][N];

void calcConst() {
  ll qnt[2][N], x[3][N];

  qnt[0][1] = 8;
  qnt[1][1] = 1;
  for(int i=2; i<N; i++) {
    qnt[0][i] = qnt[0][i-1]*9 - qnt[1][i-1];
    qnt[1][i] = qnt[0][i-1];

    //db(i _ qnt[0][i] _ qnt[1][i]);
  }

  tk[1] = qnt[0][1];
  for(int i=2; i<N; i++) for(int j=0; j<2; j++) tk[i] = tk[i-1] + qnt[0][i];
  for(int i=1; i<N; i++) 
    //db(i _ tk[i]);


  x[0][1] = 9;
  x[1][1] = x[2][1] = 1;

  for(int i=2; i<N; i++) {
    x[0][i] = x[0][i-1]*9 - x[1][i-1];
    x[1][i] = x[0][i-1];
    x[2][i] = x[0][i-1] - x[1][i-1];

  //db(i _ x[0][i] _ x[1][i] _ x[2][i]);

  }

  for(int i=1; i<10; i++) if(i!=4) t1[1][i] = 1;
  for(int i=1; i<10; i++) t1[1][i] += t1[1][i-1];
  for(int i=2; i<N; i++) {
    t1[i][1] = x[0][i-1] - x[1][i-1];
    ll tmp = qnt[0][i] - t1[i][1];
    tmp /= 7;
    for(int j=2; j<10; j++) if(j!=4) t1[i][j] = tmp;
    for(int j=2; j<10; j++) t1[i][j] += t1[i][j-1];
  }

  for(int i=0; i<10; i++) if(i!=4) t0[1][i] = 1;
  for(int i=1; i<10; i++) t0[1][i] += t0[1][i-1];
  for(int i=2; i<N; i++) {
    t0[i][1] = x[0][i-1] - x[1][i-1];
    ll tmp = x[0][i-1];

    t0[i][0] = tmp;
    for(int j=2; j<10; j++) if(j!=4) t0[i][j] = tmp;
    for(int j=1; j<10; j++) t0[i][j] += t0[i][j-1];
  }

  for(int i=0; i<10; i++) if(i!=4 and i!=3) t3[1][i] = 1;
  for(int i=1; i<10; i++) t3[1][i] += t3[1][i-1];
  for(int i=2; i<N; i++) {
    t3[i][1] = x[0][i-1] - x[1][i-1];
    ll tmp = x[0][i-1];

    t3[i][0] = tmp;
    for(int j=2; j<10; j++) if(j!=4 and j!=3) t3[i][j] = tmp;
    for(int j=1; j<10; j++) t3[i][j] += t3[i][j-1];
  }
}

int main() {

  calcConst();

  while(~scanf("%lld", &n)) {
    k = lower_bound(&tk[1], &tk[19], n) - &tk[0];
    n-=tk[k-1];
    int d = lower_bound(t1[k]+1, t1[k]+9, n)-t1[k];

    printf("%d", d);
    n -= t1[k][d-1];
    k--;

    while(k) {
      //db(k _ n);
      if(d!=1) {
        d = lower_bound(t0[k], t0[k]+9, n)-t0[k];
        //db(d _ t0[k][d]);
        printf("%d", d);
        n -= t0[k][d-1];
      }
      else {
        d = lower_bound(t3[k], t3[k]+9, n)-t3[k];
        //db(d _ t3[k][d]);
        printf("%d", d);
        n -= t3[k][d-1];
      }
      k--;
    }

    printf("\n");
  }
  return 0;
}
