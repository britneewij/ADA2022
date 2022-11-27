#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cassert>
#include <random>
#include <chrono>
#include <cmath>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <list>
#include <cstring>
#include <bits/stdc++.h>

#define int long long 
using namespace std;
#define MAXX 200001

struct Node{
  vector<int> adj;
  vector<int> radj;
};
Node g[MAXX];

stack<int> S;
int* visited = new int[MAXX];
int* id = new int[MAXX];
int num, cnt, ans;

// sort vertices by timeout
void dfs1(int x){
  if (visited[x]==1)return;
  visited[x] = 1;

  for (int i=0; i<g[x].adj.size(); i++){
    dfs1(g[x].adj[i]);
  }
  S.push(x);
}

void dfs2(int x){
  cnt++;

  id[x] = num;
  visited[x] = 1;

  for (int i=0; i<g[x].radj.size(); i++){
    if (visited[g[x].radj[i]] == 0){
      dfs2(g[x].radj[i]);
    }
  }
}

int count(int temp){
  int ans = 0;
  while (temp>0){
    temp--;
    ans += temp;
  }

  return ans;
}

signed main(){
  int n, m;
  cin >> n >> m;
  
  int a, b;
  for (int i=0; i<m; i++){
    cin >> a >> b;
    g[a-1].adj.push_back(b-1);
    g[b-1].radj.push_back(a-1);
  }

// Kosaraju
  for (int i=0; i<n; i++){
    if (visited[i] == 0){
      dfs1(i);
    }
  }

  for (int i=0; i<n; i++){
    visited[i] = 0;
  }

  while (!S.empty()){
    int x = S.top();
    S.pop();

    if (visited[x] == 0){
      cnt = 0;
      dfs2(x);
      num++;

      if (cnt>1){
        int temp = count(cnt);
        ans += temp;
      }
    }
  }

  cout<<ans<<"\n";

  return 0;
}
