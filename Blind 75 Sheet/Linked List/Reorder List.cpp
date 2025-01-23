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

Node* rev(Node* head){
    Node* curr = head;
    Node* prev = nullptr;

    while(curr){
        Node* next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    return prev;
}

int main(){
    Node* head = new Node(1);
    Node* curr = head;
    for(int i=2; i<=5; i++){
        curr->next = new Node(i);
        curr = curr->next;
    }

    Node* slow = head;
    Node* fast = head;
    while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
    }
    Node* sec = slow->next;
    slow->next = nullptr;
    slow = head;
    sec = rev(sec);

    Node* ans = new Node(-1);
    Node* dummy = ans;

    while(slow and sec){
        dummy->next = new Node(slow->data);
        dummy = dummy->next;
        slow = slow->next;

        dummy->next = new Node(sec->data);
        dummy = dummy->next;
        sec = sec->next;
    }

    if(slow) dummy->next = slow;
    if(sec) dummy->next = sec;

    ans = ans->next;
    while(ans){
        cout << ans->data << " ";
        ans = ans->next;
    }
}
