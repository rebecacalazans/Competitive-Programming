#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, a, b, c;
int ans;

int main() {
  scanf("%d%d%d%d", &n, &a, &b, &c);

  for(int i=0; i*a<=n; i++) {// i = quantidade de fitas de tamanho a
    for(int j=0; j*b+i*a <= n; j++) {// j = quantidade de fitas de tamanho b
      int r = n - i*a - j*b;// sobra da fita para dividir em pedaços de tamanho c
      if(r%c == 0) {
        ans = max(ans, i+j+r/c);
      }
    }
  }

  printf("%d\n", ans);

  return 0;
}
