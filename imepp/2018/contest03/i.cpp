#include<bits/stdc++.h>
using namespace std;

const int N = 105;

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

int n;
map<string, int> m;
char s[N];
int ans;

int main() {
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%s", s);
    ans = max(ans, ++m[s]);
  }
  printf("%d\n", ans);
  return 0;
}
