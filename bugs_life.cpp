#include <bits/stdc++.h>

using namespace std;

int nodes, edges;
int c[2010];

int main(){
  ios::sync_with_stdio(0);
  int tc;
  cin >> tc;
  for(int t = 0; t < tc; t++){
    bool bad = false;
    int x, y;
    cin >> nodes >> edges;
    vector <int> a[nodes + 1];
    for(int i = 1; i <= nodes; i++){
      c[i] = -1;
    }
    for(int i = 0; i < edges; i++){
      cin >> x >> y;
      a[x].push_back(y);
      a[y].push_back(x);
    }
    for(int i = 1; i <= nodes; i++){
      if(c[i] == -1){
        c[i] = 1;
        queue <int> q;
        q.push(i);
        while(!q.empty()){
          int v = q.front();
          q.pop();
          for(int j = 0; j < a[v].size(); j++){
            if(c[a[v][j]] == -1){
              c[a[v][j]] = 1 - c[v];
              q.push(a[v][j]);
            } else if(c[a[v][j]] == c[v]){
              bad = true;
              break;
            }
          }
          if(bad){
            break;
          }
        }
        if(bad){
          break;
        }
      } 
    } 
    if(bad){
      cout << "Scenario #" << t + 1 << ":" << endl;
      cout << "Suspicious bugs found!" << endl;
    } else{
      cout << "Scenario #" << t + 1 << ":" << endl;
      cout << "No suspicious bugs found!" << endl; 
    }
  }
  return 0;
}