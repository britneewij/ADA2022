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
#define MAX 2001;
#define INF 0x3f3f3f3f
using namespace std;

typedef pair< int, int > pii;

/*
Set MAX according to the number of nodes in the graph. Remember,
nodes are numbered from 1 to N. Set INF according to what is the
maximum possible shortest path length going to be in the graph.
This value should match with the default values for d[] array.
*/

/*
pair object for graph is assumed to be (node, weight). d[] array
holds the shortest path from the source. It contains INF if not
reachable from the source.
*/
vector<pii> G[MAX];
int d[MAX];

void dijkstra(int start){
    int u, v, c, w;

    priority_queue<pii, vector<pii>, greater<pii>> Q;

    /*
    Reset the distance array and set INF as initial value. The
    source node will have weight 0. We push (0, start) in the
    priority queue as well that denotes start node has 0 weight.
    */
    memset(d, 0x3f, sizeof d);
    Q.push(pii(0, start));
    d[start] = 0;

    // As long as queue is not empty, check each adjacent node of u

    while(!Q.empty()){
        u = Q.top().second; // node
        c = Q.top().first; // node cost
        Q.pop(); // remove the top item.

        /*
        We have discarded the visit array as we do not need it.
        If d[u] has already a better value than the currently
        popped node from queue, discard the operation on this node.
        */
        if(d[u] < c)continue;

        /*
        In case you have a target node, check if u == target node.
        If yes you can early return d[u] at this point.
        */

        /*
        Traverse the adjacent nodes of u. Remember, for the graph,
        the pair is assumed to be (node, weight).
        */
        for(int i=0; i<G[u].size(); i++) {
            v = G[u][i].first; // node
            w = G[u][i].second; // weight

            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                Q.push(pii(d[v], v));
            }
        }
    }
}

signed main() {
    int n, m;
    int a, b, c;

    cin >> n >> m; //n nodes, m edges

    // init reset
    for(int i=1; i<=n; i++){
        G[i].clear();
    }

    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        G[a].push_back(pii(b, c));
    }

    int min_sum = INF;
    int sum;
    int start = 1;
    for (int i=2; i<=n; i++){
        //cout << "i " << i << "\n";
        G[1].push_back(pii(i, 0));
        dijkstra(start);

        sum = 0;
        for(int j=2; j<=n; j++){
            if (d[j] >= INF) continue;
            //cout << "d[j] " << d[j] << "\n";
            sum += d[j];
        }
        //cout << "sum " << sum << "\n";
        //cout << "min sum 1 " << min_sum << "\n";
        if (sum < min_sum){
            min_sum = sum;
        }
        //cout << "min sum 2 " << min_sum << "\n";
        G[1].pop_back();
    }
    cout << min_sum << "\n";
    return 0;
}
