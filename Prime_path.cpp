#include <bits/stdc++.h>
 
using namespace std;

#define MAX 10001

bool isprime[MAX];
bool done[MAX];
vector <int> pr;
vector <int> ad[MAX];
int dis[MAX];

void pre() {
  memset(isprime, true, sizeof isprime);
  isprime[0] = isprime[1] = false;
  for (int i = 2; i * i <= MAX; i++) {
    if (isprime[i]) {
      for (int j = i * i; j <= MAX; j += i) {
        isprime[j] = false;
      }
    }
  }
  for (int i = 1000; i < MAX; i++) {
    if (isprime[i]) {
      pr.push_back(i);
    }
  }
}

int dif(int a, int b) {
  int res = 0;
  int da[4], db[4];
  int ca = 0, cb = 0;
  while (a > 0) {
    da[ca] = (a % 10);
    a /= 10;
    ca++;
  }
  while (b > 0) {
    db[cb] = (b % 10);
    b /= 10;
    cb++;
  }
  for (int i = 0; i < 4; i++) {
    if (da[i] != db[i]) {
      res++;
    }
  }
  return res;
}

void pre2() {
  for (int i = 0; i < (int) pr.size(); i++) {
    for (int j = 0; j < (int) pr.size(); j++) {
      if (dif(pr[i], pr[j]) == 1) {
        ad[pr[i]].push_back(pr[j]);
      }
    }
  }
}
 
int main() {
  #ifdef HOME
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
  #endif
  pre();
  pre2();
  int tc, a, b;
  cin >> tc;
  for (int tt = 0; tt < tc; tt++) {
    memset(done, false, sizeof done);
    for (int i = 0; i < MAX; i++) {
      dis[i] = 1e9;
    }
    queue <int> q;
    cin >> a >> b; 
    q.push(a);
    done[a] = true;
    dis[a] = 0;
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int i = 0; i < (int) ad[v].size(); i++) {
        if (!done[ad[v][i]]) {
          done[ad[v][i]] = true;
          q.push(ad[v][i]);
        }
        dis[ad[v][i]] = min(dis[ad[v][i]], dis[v] + 1);
      }
    }
    printf("%d\n", dis[b]);
  }
  return 0;
} 