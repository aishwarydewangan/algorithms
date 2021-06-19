#include <bits/stdc++.h>

using namespace std;

bool isCycle(int v, vector<bool> &visited, vector<bool> &recStack, vector<int> graph[]) {
    
    visited[v] = recStack[v] = true;
    
    for(int u : graph[v]) {
        if(!visited[u]) {
            if(isCycle(u, visited, recStack, graph)) {
                return true;
            }
        } else if(recStack[u]) {
            return true;
        }
    }
    
    recStack[v] = false;
    
    return false;
}

void addEdge(int u, int v, vector<int> graph[]) {
    graph[u].push_back(v);
}

int main() {
    //Assumption: Nodes start from 1 to N
    
    int N = 9;
    
    vector<bool> visited(N+1, false);
    
    vector<bool> recStack(N+1, false);
    
    vector<int> graph[N+1];
    
    addEdge(1, 2, graph);
    addEdge(2, 3, graph);
    addEdge(3, 4, graph);
    addEdge(4, 5, graph);
    addEdge(3, 6, graph);
    addEdge(6, 5, graph);
    addEdge(7, 2, graph);
    addEdge(7, 8, graph);
    addEdge(8, 9, graph);
    addEdge(9, 7, graph);
    
    bool flag = false;
    
    for(int i = 1; i <= N; i++) {
        if(!visited[i]) {
            flag = isCycle(i, visited, recStack, graph);
        }
    }
    
    if(flag) {
        cout << "Cycle found";
    } else {
        cout << "Cycle not found";
    }
    return 0;   
}