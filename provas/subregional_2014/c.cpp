#include <bits/stdc++.h>
using namespace std;

int n, m;
int c[505][4];
int x, y, z, i;
map<string, int> t;
int maxi;
char str[505];

int main() {
  scanf("%d%d", &m, &n);
  for (i = 0; i < m; i++) for (int j = 0; j<4; j++) scanf("%d", &c[i][j]);
  str[m] = '\0';
  for (int j = 0; j < n; j++) {
    scanf("%d%d%d", &x, &y, &z);
    for (i=0; i<m; i++) {
      int ans = c[i][0]*x+c[i][1]*y+c[i][2]*z;
      if(ans<=c[i][3]) str[i] = 'b';
      else str[i] = 'a';
    }
    maxi = max(++t[str], maxi);
  }
  printf("%d\n", maxi);
}
