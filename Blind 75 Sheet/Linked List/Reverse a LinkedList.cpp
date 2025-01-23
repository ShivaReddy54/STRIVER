#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Node{
public:
    int data;
    Node* next;

    Node(int n){
        data = n;
        next = nullptr;
    }
};

int main(){
    Node* root = new Node(1);
    Node* curr = root;
    for(int i=2; i<=5; i++){
        curr->next = new Node(i);
        curr = curr->next;
    }

    // Reverse
    // Time --> O(N)
    curr = root;
    Node* prev = nullptr;

    while(curr){
        Node* next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    root = prev;
}