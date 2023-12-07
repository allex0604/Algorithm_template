#include <bits/stdc++.h>
using namespace std;

class Trie {
    bool isEnd;
    Trie* child[26];
    Trie() {
        this->isEnd = false;
        for (int i = 0; i < 26; i++)
            this->child[i] = NULL;
    }

    void insert(string word) {
        Trie* root = this;
        for (auto& ch : word) {
            int i = ch - 'a';
            if (root->child[i] == NULL)
                root->child[i] = new Trie();
            root = root->child[i];
        }
        root->isEnd = true;
    }

    bool search(string word) {
        Trie* root = this;
        for (auto& ch : word) {
            int i = ch - 'a';
            if (root->child[i] == NULL)
                return false;
            root = root->child[i];
        }
        if(root->isEnd)
            return true;
        return false;
    }

    bool startsWith(string prefix){
        return search(prefix);
    }
};

int64_t main() {
    return 0;
}
