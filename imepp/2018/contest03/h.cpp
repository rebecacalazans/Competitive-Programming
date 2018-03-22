#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int n;
stack<string> st;
char s[N];


int main() {
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%s", s);
    if(!strcmp(s, "Sleep")) {
      scanf("%s", s);
      st.push(s);
    }
    else if(!strcmp(s, "Test")) {
      if(st.empty()) {
        printf("Not in a dream\n");
      }
      else printf("%s\n", st.top().c_str());
    }
    else {
      if(!st.empty()) {
        st.pop();
      }
    }
  }
}
