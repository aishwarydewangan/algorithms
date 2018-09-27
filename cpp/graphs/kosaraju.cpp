#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> graph[5];
bool visited[5];
vector<int> transposeGraph[5];
stack<int> order;


void dfs(int v) {
	visited[v] = true;

	for(int i = 0; i < graph[v].size(); i++) {
		if(!visited[graph[v][i]])
			dfs(graph[v][i]);
	}

	order.push(v);
}

void printSCC(int v) {
	visited[v] = true;

	cout << v << " ";

	for(int i = 0; i < transposeGraph[v].size(); i++) {
		if(!visited[transposeGraph[v][i]])
			printSCC(transposeGraph[v][i]);
	}
}

int main() {
	int n = 5, e = 5;
	cout << "\nEnter edges: ";
	while(e--) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		transposeGraph[b].push_back(a);
	}

	for(int i = 0; i < 5; i++)
		visited[i] = false;

	for(int i = 0; i < 5; i++) {
		if(!visited[i])
			dfs(i);
	}

	cout << "\nConnected components:\n";

	for(int i = 0; i < 5; i++)
		visited[i] = false;

	while(!order.empty()) {
		int v = order.top();
		order.pop();

		if(visited[v] == false) {
			printSCC(v);
			cout << endl;
		}
	}
}