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

using namespace std;
#define int long long 

const int MAXX = 1000001;
typedef pair<int, int> edge;
vector<edge> adj[MAXX];
int* inMST = new int[MAXX];

void prim(int x){
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    pq.push(make_pair(0, x));
    edge p;

    int y;
    int min = 0;
    while(!pq.empty()){
        p = pq.top();
        pq.pop();
        x = p.second;

        if(inMST[x]==1){
            continue;
        }
        inMST[x] = 1;

        for(int i=0; i<adj[x].size(); ++i){
            y = adj[x][i].second;

            if(inMST[y]==0){
                pq.push(adj[x][i]);
            }
        }
        min += p.first;
    }

    cout << min << "\n";
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;

    int node1, node2, cost;
    for (int i=0; i<m; i++){
        cin >> node1 >> node2 >> cost;

        adj[node1].push_back(make_pair(cost, node2));
        adj[node2].push_back(make_pair(cost, node1));
    }

    prim(1);
    return 0;
}
