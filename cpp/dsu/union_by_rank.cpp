#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n, m;

vector<int> parent(100001);
vector<int> rank(100001);

void makeSet() {
    for(int i = 0; i < parent.size(); i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(int v) {
    if(v == parent[v])
        return v;
    return parent[v] = findParent(parent[v]);
}

void unionSet(int a, int b) {
	
    a = findParent(a);
    b = findParent(b);
    
    if(a != b) {
        if(rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if(rank[a] == rank[b])
            rank[a]++;
    }
}

int main() {
    cin >> n >> m;
    parent.resize(n+1);
    makeSet();
    while(m--) {
        int a, b;
        cin >> a >> b;
        unionSet(a, b);
    }
    return 0;
}