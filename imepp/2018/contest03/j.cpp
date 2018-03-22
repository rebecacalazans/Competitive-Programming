#include<bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

const int N = 1e5+5;

int n, m;
int d[N], a[N];
int cont;

bool test(int x) {
  int day[N] = {0};
  int tot = 0, ex = 0;

  for(int i=0; i<x; i++) {
    day[d[i]] = i;
  }

  for(int i=0; i<x; i++) {
    if(d[i] != 0 and  day[d[i]] == i) {
      tot -= a[d[i]];
      ex++;
      if(tot < 0) return false;
    }
    else {
      tot++;
    }
  }
  if(ex < m) return false;
  return true;
}

int bs(int l, int r) {
  while(l < r) {
    int m = (l+r)/2;
    if(test(m)) r = m;
    else l = m+1;
  }
  return r;
}


int main() {
  scanf("%d%d", &n, &m);
  for(int i=0; i<n; i++) {
    scanf("%d", &d[i]);
  }
  for(int i=1; i<=m; i++) {
    scanf("%d", &a[i]);
  }

  if(!test(n)) {
    printf("-1\n");
    return 0;
  }

  printf("%d\n", bs(0, n));
  return 0;
}
