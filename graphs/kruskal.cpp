#include <bits/stdc++.h>

using namespace std;

void makeSet(vector<int> &parent) {
    for(int i = 0; i < parent.size(); i++) {
        parent[i] = i;
    }
}

int findParent(vector<int> &parent, int v) {
    if(v == parent[v]) {
        return v;
    }
    return parent[v] = findParent(parent, parent[v]);
}

void unionSet(vector<int> &parent, int a, int b) {
    a = findParent(parent, a);
    b = findParent(parent, b);
    if(a != b) {
        parent[b] = a;
    }
}

void kruskal() {
    int n, e;
    cout << "\nEnter no. of vertices: ";
    cin >> n;
    vector<int> nodes(n+1);
    makeSet(nodes);
    cout << "\nEnter no. of edges: ";
    cin >> e;
    pair<int, pair<int, int>> graph[n+1];
    for(int i = 0; i < e; i++) {
        int a, b, w;
        cout << "\nEnter edge and weight(a, b, w): ";
        cin >> a >> b >> w;
        graph[i] = make_pair(w, make_pair(a, b));
    }
    sort(graph, graph+e);
    int cost = 0;
    for(int i = 0; i < e; i++) {
        int a, b, w;
        a = graph[i].second.first;
        b = graph[i].second.second;
        w = graph[i].first;
        if(findParent(nodes, a) != findParent(nodes, b)) {
            cost += w;
            unionSet(nodes, a, b);
        }
    }
    cout << "\nCost of Minimum Spanning Tree: " << cost;
}

int main() {
    kruskal();
    return 0;
}