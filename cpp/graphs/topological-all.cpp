#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> graph[20];
bool visited[20];
vector<int> odr;
int nd, ed;
map<int, int> inDegree;

void dfs() {
    bool flag = false;
    
    for(int i = 1; i <= nd; i++) {
        if(inDegree[i] == 0 && !visited[i]) {
            for(int j = 0; j < graph[i].size(); j++)
                inDegree[graph[i][j]]--;
            odr.push_back(i);
            visited[i] = true;
            dfs();
            visited[i] = false;
            odr.pop_back();
            for(int j = 0; j < graph[i].size(); j++)
                inDegree[graph[i][j]]++;
            
            flag = true;
        }
    }
    
    if(!flag) {
        for(int i = 0; i < odr.size(); i++)
            cout << odr[i] << " ";
        cout << endl;
    }
}

int main() {
    //ALL Topological Order of a Graph
    cin >> nd >> ed;
    
    for(int i = 1; i <= nd; i++) {
        inDegree[i] = 0;
    }
    
    while(ed--) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        inDegree[b]++;
    }
    
    for(int i = 1; i <= nd; i++) {
        visited[i] = false;
    }
    dfs();
}