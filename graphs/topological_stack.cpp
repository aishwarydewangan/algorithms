#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

vector<int> graph[20];
bool visited[20];
vector<int> odr;
int nd, ed;
stack<int> stk;

void dfs(int v) {
    visited[v] = true;
    
    for(int i = 0; i < graph[v].size(); i++) {
        if(!visited[graph[v][i]])
            dfs(graph[v][i]);
    }
    
    stk.push(v);
}

int main() {
    cin >> nd >> ed;
    
    for(int i = 1; i <= nd; i++) {
        visited[i] = false;
    }
    
    while(ed--) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    
    for(int i = 1; i <= nd; i++) {
        if(!visited[i])
            dfs(i);
    }
    while(!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    return 0;
}