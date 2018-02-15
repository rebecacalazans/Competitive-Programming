#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

char s[N];
int cont[26];
int ans;

int main() {
  while(~scanf("%s", s)) {
    ans = 0;
    for(int i=0; i<26; i++) cont[i] = 0;
    for(int i=0; s[i]; i++) {
      cont[s[i]-'a']++;
    }
    for(int i=0; i<26; i++) {
      ans += cont[i]%2;
    }
    printf("%d\n", max(0, ans-1));
  }
}
