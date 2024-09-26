#include<iostream>

using namespace std;

class Node{
public:
    Node* next;
    int data;
    Node(int data){
        this->data=data;
    }
    Node(int data,Node* next){
        this->data=data;
        this->next=next;
    }
};

Node* create(int arr[]){
    Node* head=new Node(arr[0]);
    Node* ins=head;
    for(int i=1;i<11;i++){
        Node* temp=new Node(arr[i]);
        ins->next=temp;
        ins=temp;
    }
    return head;
}

void iterate(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

Node* add(Node* head,int element,int i){
    Node* temp=head;
    int a=0;
    while(temp->next!=nullptr){
        a++;
        temp=temp->next;
        if(a==i-1){
            Node* q = new Node(element);
            q->next=temp->next;
            temp->next=q;
            break;
        }
    }
    return head;
}

Node* remove(Node* head,int i){
        Node* temp=head;
    int a=0;
    while(temp->next!=nullptr){
        a++;
        temp=temp->next;
        if(a==i-1){
            temp->next=temp->next->next;
            break;
        }
    }
    return head;
}

int main(){
    int arr[11]={3,3,3,1,2,1,1,2,3,3,4};
    iterate(remove(create(arr),2));

}