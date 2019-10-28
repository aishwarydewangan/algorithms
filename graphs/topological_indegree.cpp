#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, e;
    map<int, int> indegree;
    cout << "\nEnter no. of vertices: ";
    cin >> n;
    vector<int> graph[n+1];
    cout << "\nEnter no. of edges: ";
    cin >> e;
    for(int i = 0; i < e; i++) {
        int a, b;
        cout << "\nEnter edge(a->b): ";
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    cout << "\nTopological Sort: ";
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v;
        for(int i = 0; i < graph[v].size(); i++) {
            indegree[graph[v][i]]--;
            if(indegree[graph[v][i]] == 0) {
                q.push(graph[v][i]);
            }
        }
    }
    return 0;
}