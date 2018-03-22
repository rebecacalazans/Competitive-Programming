#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

long long n;
long long ans;

long long fexp(long long a, long long b) {
  long long ans = 1;
  for(a%=MOD; b; b>>=1, a = (a*a)%MOD) if(b&1) ans = (ans*a)%MOD;
  return ans;
}

int main() {
  scanf("%lld", &n);
  long long ans = fexp(2, n);
  ans = (((ans+1)*ans)/2)%MOD;

  printf("%lld\n", ans);
}
