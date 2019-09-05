#include <iostream>
#include <string>

using namespace std;

struct Trie {
    Trie *child[26];
    bool endOfString;
};

Trie* newNode() {
    Trie *node = new Trie;
    
    node->endOfString = false;
    
    for(int i = 0; i < 26; i++)
        node->child[i] = NULL;
        
    return node;
}

void insert(Trie *root, string str) {
    Trie *temp = root;
    for(int i = 0; i < str.size(); i++) {
        if(temp->child[str[i]-'a'] == NULL)
            temp->child[str[i]-'a'] = newNode();
        temp = temp->child[str[i]-'a'];
    }
    temp->endOfString = true;
}

int search(Trie *root, string key) {
    Trie *temp = root;
    for(int i = 0; i < key.size(); i++) {
        if(temp->child[key[i]-'a'] == NULL)
            return 0;
        temp = temp->child[key[i]-'a'];
    }
    if(temp->endOfString)
        return 1;
    return 0;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        Trie *root = newNode();
        while(n--) {
            string str;
            cin >> str;
            insert(root, str);
        }
        string key;
        cin >> key;
        cout << search(root, key) << endl;
    }
	return 0;
}