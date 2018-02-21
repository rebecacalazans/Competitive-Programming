#include<bits/stdc++.h>
using namespace std;


int main() {
  int a[3],b[3];
  int ans = 0;
  for(int i=0; i < 3; i++) scanf("%d", &a[i]);
  for(int i=0; i < 3; i++) scanf("%d", &b[i]);
  for(int i=0; i < 3; i++) if(a[i] < b[i]) ans-=a[i]-b[i];
  printf("%d\n", ans);
  return 0;
}
