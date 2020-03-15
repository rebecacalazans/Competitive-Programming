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
const int N = 1e5+5;

char q, c;
ll pos;
map<ll, char> added[2];
set<ll> removed[2];

void add(ll pos, char c, int x) {
  map<ll, char> m;
  for(auto p: added[x]) {
    if(p.st < pos) m[p.st] = p.nd;
    else m[p.st+1] = p.nd;
  }
  m[pos] = c;
  swap(m, added[x]);
}

void remove(ll pos, int x) {
  map<ll, char> m;
  for(auto p: added[x]) {
    if(p.st < pos) m[p.st] = p.nd;
    else if(p.st > pos) m[p.st-1] = p.nd;
  }
  swap(m, added[x]);

  if(m.count(pos)) return;

  ll p = pos;

  for(auto it: m) if(it.st < pos) p--;
  for(auto it: removed[x]) if(it <= p) p++;

  removed[x].insert(p);
}

int main() {
  for(int i = 0; i < 2; i++) {
    while(scanf(" %c", &q), q != 'E') {
      scanf("%lld", &pos);
      if(q == 'I') {
        scanf(" %c", &c);
        add(pos, c, i);
      }
      else {
        remove(pos, i);
      }
    }
  }
  /*
  for(int i = 0; i < 2; i++) {
    db(i);
    for(auto s: removed[i]) db(s);
  }
  for(int i = 0; i < 2; i++) {
    db(i);
    for(auto s: added[i]) db(s.st _ s.nd);
  }
  */

  if(added[0].size() != added[1].size()) {
    printf("1\n");
    return 0;
  }
  if(removed[0].size() != removed[1].size()) {
    printf("1\n");
    return 0;
  }

  for(auto p: added[0]) {
    if(added[1][p.st] != p.nd) {
      printf("1\n");
      return 0;
    }
  }

  for(auto p: removed[0]) {
    if(!removed[1].count(p)) {
      printf("1\n");
      return 0;
    }
  }

  printf("0\n");
  return 0;
}
