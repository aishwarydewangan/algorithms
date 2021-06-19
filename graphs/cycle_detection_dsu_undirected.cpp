#include <bits/stdc++.h>

using namespace std;

vector<int> parent;

void makeSet(int N) {
    parent.resize(N+1, -1);
}

int findParent(int v) {
    if(parent[v] == -1)
        return v;
    return findParent(parent[v]);
}

void unionSet(int u, int v) {
    u = findParent(u);
    v = findParent(v);
    
    if(u != v) {
        parent[v] = u;
    }
}

void addEdge(int u, int v, vector<pair<int, int>> &graph) {
    graph.push_back({u, v});
}

int main() {
    //Assumption: Nodes start from 1 to N
    
    int N = 4;
    
    vector<pair<int, int>> graph;
    
    addEdge(1, 2, graph);
    addEdge(2, 3, graph);
    addEdge(3, 4, graph);
    addEdge(4, 1, graph);
    
    int E = graph.size();
    
    makeSet(N);
    
    bool flag = false;
    
    for(int i = 0; i < E; i++) {
        int u = findParent(graph[i].first);
        int v = findParent(graph[i].second);
        
        if(u != v) {
            unionSet(u, v);
        } else {
            flag = true;
            break;
        }
    }
    
    if(flag) {
        cout << "Cycle found";
    } else {
        cout << "Cycle not found";
    }
    
    return 0;   
}