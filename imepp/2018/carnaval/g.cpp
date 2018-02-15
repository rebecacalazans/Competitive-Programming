#include<bits/stdc++.h>
using namespace std;

long long pa[22][100];
int l;
long long ans;

int main() {
  pa[0][2] = 1;

  for(int i=1; i<=20; i++) {
    for(int j=0; j<2*i+1; j++) {
      pa[i][j+2] = pa[i-1][j]+pa[i-1][j+1]+pa[i-1][j+2];
    }
  }
  /*
  for(int i=0; i<20; i++) {
    for(int j=0; j<2*i+1; j++) {
      printf("%lld ", pa[i][j+2]);
    }
    printf("\n");
  }
  */
  scanf("%d", &l);
  for(int i=0; i<2*l+1; i++) ans+=pa[l][i+2];
  printf("%lld\n", ans);
  return 0;
}
