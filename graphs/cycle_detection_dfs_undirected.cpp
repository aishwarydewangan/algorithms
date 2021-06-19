#include <bits/stdc++.h>

using namespace std;

bool isCycle(int v, int parent, vector<bool> &visited, vector<int> graph[]) {
    
    visited[v] = true;
    
    for(int u : graph[v]) {
        if(!visited[u]) {
            if(isCycle(u, v, visited, graph)) {
                return true;
            }
        } else if(u != parent) {
            return true;
        }
    }
    
    return false;
}

void addEdge(int u, int v, vector<int> graph[]) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

int main() {
    //Assumption: Nodes start from 1 to N
    
    int N = 4;
    
    vector<bool> visited(N+1, false);
    
    vector<int> graph[N+1];
    
    addEdge(1, 2, graph);
    addEdge(2, 3, graph);
    addEdge(3, 4, graph);
    addEdge(4, 1, graph);
    
    bool flag = false;
    
    for(int i = 1; i <= N; i++) {
        if(!visited[i]) {
            flag = isCycle(i, -1, visited, graph);
        }
    }
    
    if(flag) {
        cout << "Cycle found";
    } else {
        cout << "Cycle not found";
    }
    return 0;   
}