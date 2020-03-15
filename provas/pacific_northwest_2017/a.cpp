#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e2+5;

char s[N];

bool is_palindrome(int i, int j) {
  for(; i < j; i++, j--) if(s[i] != s[j]) return false;
  return true;
}

int main() {
  scanf("%s", s);

  for(int i = 0; s[i]; i++) {
    for(int j = i; s[j]; j++) {
      if((j-i+1)%2 == 0) {
        if(is_palindrome(i, j)) {
          printf("Or not.\n");
          return 0;
        }
      }
    }
  }

  printf("Odd.\n");

  return 0;
}
