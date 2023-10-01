#include <bits/stdc++.h>

struct Node{
int data;
Node *next;
Node(int nodeInput){
this->data = nodeInput;
this->next = nullptr;
}
};


class singleLinkedList{
private:
Node *head;

// create nodes with inserting
void insertEndUtil(int data){
Node *newNode = new Node(data);
if(this -> head == nullptr){
this -> head = newNode;
}else{
Node *ptr = this -> head;
while(ptr -> next != nullptr){
ptr = ptr -> next;
}
ptr -> next = newNode;
}
}
public:

// single link list implementation
singleLinkedList(){
head = nullptr;
}

void display(){
Node *ptr = this -> head;
while(ptr){
std::cout<<ptr -> data<<" ";
ptr = ptr->next;
}
std::cout << std::endl;
}

// list for nodes created
void creatList(int n){
for(int i=0; i<n ; i++){
int nodeList;
std::cout << " Node "<< (i + 1) <<": ";
std::cin >> nodeList;
this -> insertEndUtil(nodeList);
}
}

// node deleted at the middle 
void delete_at_mid(){
if (this->head == nullptr) {
return;
}
if (this -> head -> next == nullptr) {
delete this -> head;
this->head = nullptr;
return;
}

Node* left = this -> head;
Node* right = this -> head;

struct Node* prevPtr;
while (right != nullptr && right -> next != nullptr){
right = right->next->next;
prevPtr = left;
left = left->next;
}
prevPtr->next = left->next;
// deleting the middle
delete left;
}

void insert_at_mid(int nodeInput){
// if linked list is empty (nullptr)
if (this -> head == nullptr)
this -> head = new Node(nodeInput);
else {
// new node is created
Node* newNode = new Node(nodeInput);

Node* left = this -> head;
Node* right = this -> head -> next;
while (right && right -> next) {
left = left -> next;
right = right -> next -> next;
}

newNode -> next = left -> next;
left -> next = newNode;
}
}
};

int main()
{
singleLinkedList nodeList;
nodeList.creatList(8);
nodeList.display();
nodeList.delete_at_mid();
nodeList.display();
nodeList.insert_at_mid(6);
nodeList.display();
return 0;
}