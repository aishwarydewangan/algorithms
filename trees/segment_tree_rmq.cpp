#include <bits/stdc++.h>

using namespace std;

vector<int> nums, tree;

void build(int v, int start, int end) {
    if(start == end) {
        tree[v] = nums[start];
    } else {
        int mid = (start+end)/2;
        build(2*v+1, start, mid);
        build(2*v+2, mid+1, end);
        tree[v] = min(tree[2*v+1], tree[2*v+2]);
    }
}

void update(int v, int index, int val, int start, int end) {
    if(start == end) {
        nums[index] = val;
        tree[v] = val;
    } else {
        int mid = (start+end)/2;
        if(start <= index && index <= mid) {
            update(2*v+1, index, val, start, mid);
        } else {
            update(2*v+2, index, val, mid+1, end);
        }
        tree[v] = min(tree[2*v+1], tree[2*v+2]);
    }
}

int query(int v, int start, int end, int l, int r) {
    if(r < start || l > end) {
        return INT_MAX;
    }
    if(l <= start && end <= r) {
        return tree[v];
    }
    int mid = (start+end)/2;
    int n1 = query(2*v+1, start, mid, l, r);
    int n2 = query(2*v+2, mid+1, end, l, r);
    return min(n1, n2);
}

int main() {
    int n;
    cin >> n;
    nums.resize(n);
    tree.resize(2*n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];
    build(0, 0, n-1);
    cout << query(0, 0, n-1, 2, 4);
    return 0;
}