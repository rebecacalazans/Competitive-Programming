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
int botas[100][2];
int x, ans;
char c;

int main() {
  while(~scanf("%d", &n)) {
    cl(botas, 0);
    ans = 0;
    for(int i=0; i<n; i++) {
      scanf("%d %c", &x, &c);
      botas[x][c-'D']++;
    }
    for(int i=30; i<=60; i++) ans+=min(botas[i][0], botas[i][1]);
    printf("%d\n", ans);
  }
  return 0;
}
