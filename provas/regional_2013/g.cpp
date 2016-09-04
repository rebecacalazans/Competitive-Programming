#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, y) memset(x, y, sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const long long INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7, N = 1e5+5, K = 150000;

int n;
long long h[N], stmi[3*N];

void buildmi(int p, int l, int r) {
  if(l==r) {
    stmi[p] = h[l];
    return;
  }
  buildmi(2*p, l, (l+r)/2);
  buildmi(2*p+1, (l+r)/2+1, r);
  stmi[p] = min(stmi[2*p], stmi[2*p+1]);
}
long long query(int p, int l, int r, int i, int j) {
  if(l>=i && r<=j) return stmi[p];
  if(l>j || r<i) return INF;
  return min(query(2*p, l, (l+r)/2, i, j), query(2*p+1, (l+r)/2+1, r, i, j));
}

vector<pair<long long, int> > a;
set<int> b;
queue<int> q;
set<int>::iterator it;
vi ans;

int main() {
  while(~scanf("%d", &n)) {
    cl(stmi, 63);
    ans.clear();
    a.clear();
    b.clear();

    for(int i=1; i<=n; i++) scanf("%lld", &h[i]), a.pb(mp(-h[i], i));
    buildmi(1,1,n);
    sort(a.begin(), a.end());

    for(int i=0; i<n;) {
      long long alt = a[i].first;
      while(i<n and a[i].first==alt) {
        int pos = a[i].second;
        i++;
        q.push(pos);
        if(b.empty()) {
          ans.pb(pos);
          continue;
        }
        it = b.upper_bound(pos);
        if(!(it == b.end() || query(1,1,n,pos,*it)<= h[pos]-K)) continue;
        if(!(it == b.begin() || query(1,1,n,*(--it), pos)<= h[pos]-K)) continue;
        ans.pb(pos);
      }

      while(!q.empty()) b.insert(q.front()), q.pop();
    }

    sort(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++) {
      printf("%d%c", ans[i], i==ans.size()-1?'\n':' ');
    }
  }
  return 0;
}
