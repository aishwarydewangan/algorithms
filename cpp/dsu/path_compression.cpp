#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n, m;

vector<int> parent(100001);
map<int, int> mp;

void makeSet() {
    for(int i = 0; i < parent.size(); i++) {
        parent[i] = i;
        mp[i] = 0;
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
        parent[b] = a;
    }
}

//Counts no. of elements in the set
void countParent(int v) {
    mp[findParent(v)]++;
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
    for(int i = 1; i <= n; i++) {
        countParent(i);
    }
    for(int i = 1; i <= n; i++) {
        cout << mp[findParent(i)]-1 << " ";
    }
    return 0;
}