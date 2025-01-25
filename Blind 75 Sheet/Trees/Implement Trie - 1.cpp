#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Trie{
public:
    Trie* child[26];
    bool end;

    Trie(){
        for(int i=0; i<26; i++) child[i] = nullptr;
        end = 0;
    }
};
Trie* root = new Trie();

void insert(string s){
    Trie* curr = root;

    for(auto i : s){
        int id = i - 'a';

        if(!curr->child[id]) curr->child[id] = new Trie();
        curr = curr->child[id];
    }
    curr->end = 1;
}

bool search(string s){
    Trie* curr = root;
    for(auto i : s){
        int id = i - 'a';
        if(!curr->child[id]) return 0;
        curr = curr->child[id];
    }
    return curr->end;
}

bool startsWith(string s){
    Trie* curr = root;
    for(auto i : s){
        int id = i - 'a';
        if(!curr->child[id]) return 0;
        curr = curr->child[id];
    }
    return 1;
}


int main(){
    insert("apple");
    cout << search("apple") << endl;
    cout << search("app") << endl;
    cout << startsWith("app") << endl;
    insert("app");
    cout << search("app");
}



