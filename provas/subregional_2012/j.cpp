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
int n, m;
int trie[2][805][3], trien[2];
int dp[805][805];
char s[45];

int addtrie(int t, int u, char c) {
  c-='0';
  if(trie[t][u][c]) return trie[t][u][c];
  return trie[t][u][c]=++trien[t];
}

void bfs(int a, int b) {
  if(dp[a][b]++) return;
  if(trie[0][a][2] && trie[1][b][2]) {
    dp[0][0]++;
    return;
  }
  for(int i=0; i<=1; i++) {
    if(trie[0][a][i] && trie[1][b][i]) bfs(trie[0][a][i], trie[1][b][i]);
  }
  if(trie[0][a][2]) bfs(0, b);
  if(trie[1][b][2]) bfs(a, 0);
}

int main() {
  while(scanf("%d%d", &n, &m)!=EOF) {
    memset(trie, 0, sizeof(trie));
    memset(dp, 0, sizeof(dp));
    trien[0]=trien[1]=0;
    for(int i=0; i<n; i++) {
      scanf("%s", s);
      int u=0;
      for(int i=0; s[i]; i++) u=addtrie(0, u, s[i]);
      trie[0][u][2]=1;
    }
    for(int i=0; i<m; i++) {
      scanf("%s", s);
      int u=0;
      for(int i=0; s[i]; i++) u=addtrie(1, u, s[i]);
      trie[1][u][2]=1;
    }
    bfs(0, 0);
    printf("%c\n", dp[0][0]>1?'S':'N');
  }
  return 0;
}
