#include <bits/stdc++.h>

using namespace std;

void prim() {
    int n, e;
    cout << "\nEnter no. of vertices: ";
    cin >> n;
    cout << "\nEnter no. of edges: ";
    cin >> e;
    vector<pair<int, int>> graph[n+1];
    bool visited[n+1];
    for(int i = 0; i <= n; i++) {
        visited[i] = false;
    }
    for(int i = 0; i < e; i++) {
        int a, b, w;
        cout << "\nEnter edge and it's weight(a, b, w): ";
        cin >> a >> b >> w;
        graph[a].push_back(make_pair(w, b));
        graph[b].push_back(make_pair(w, a));
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int a = 1, cost = 0, b;
    pq.push(make_pair(0, a));
    while(!pq.empty()) {
        pair<int, int> p = pq.top();
        pq.pop();
        a = p.second;
        if(visited[a]) {
            continue;
        }
        cost += p.first;
        visited[a] = true;
        for(int i = 0; i < graph[a].size(); i++) {
            b = graph[a][i].second;
            if(!visited[b]) {
                pq.push(graph[a][i]);
            }
        }
    }
    cout << "\nCost of Minimum Spanning Tree: " << cost;
}

int main() {
    prim();
    return 0;
}