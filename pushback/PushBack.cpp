#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    struct node *next;
};


typedef struct node node; //C


void duyet(node *head){
    while (head != NULL){
        cout<<head->data <<' ';
        //printf("%d",head->data); C
        head = head -> next;
    }
}

node* makeNode(int x){
    node *newNode = new node();//C++
    //node *newNode = (node*)malloc(sizeof(node)); C
    newNode -> data =x;
    newNode -> next = NULL;
    return newNode;
}


//pushBack đúng khi có ít nhất 1 node, nếu chưa có thì lỗi bộ nhớ
void pushBack(node **head, int x){
    node *temp = *head;// Tạo một biến temp để không thay đổi giá trị trong dslk
    node *newNode = makeNode(x);
    //nếu nó là node đầu tiên của dslk
    if(*head == NULL){
        *head = newNode;
        return;
    }
    while (temp -> next != NULL)
    {
        temp = temp -> next;
    }
    //Cho phần next của node head ->newNode;
    temp -> next = newNode;
}

//Code C++
void pushBack2(node *&head, int x){
    node *temp = head;
    //Danh sách liên kết ban đầu rỗng nên head sẽ bằng null
    node *newNode = makeNode(x);
    
    if (head == NULL){
        head = newNode;
        return;
    }
    //Truy cập vào phần next của một node NULL sẽ bị lỗi bộ nhớ
    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = newNode;
}

int main(){
    node *head = NULL;
    for (int i = 1; i <= 10; i++)
    {
        pushBack2(head, i);
    }
    duyet(head);
    return 0;
}

//time: 10:20