#include<bits/stdc++.h>
using namespace std;

int n, a, b;
int pta, ptb;

int main() {
  while(scanf("%d", &n), n) {
    pta = ptb = 0;
    for(int i=0; i<n; i++) {
      scanf("%d%d", &a, &b);
      if(a > b) pta++;
      if(b > a) ptb++;
    }
    printf("%d %d\n", pta, ptb);
  }
  return 0;
}
