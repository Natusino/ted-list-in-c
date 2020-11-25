#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
int age;
 struct Node *nextNode;
}n;

n* createNew(int data,n * previousNode){
n* new_node=(n*)malloc(sizeof(n));
new_node->age=data;
if(previousNode!=NULL)
previousNode->nextNode=new_node;
return new_node;
}

n* prepend(int data){
return createNew(data,NULL);
}

//Prepend: Create the head node

n* append(int data,n *previousNode){
if(previousNode==NULL){
printf("You can not append to a NULL node");
    exit(0);
}

n* newNode=createNew(data,previousNode);
return newNode;
}

//Append : Add to tail: Addition of a new node
//Insertion : Inserting a new nod between two consective nodes
//Deletion: remove a node from the list
//Travervasal : navigate through the list given the starting node

void traverser(n * startingNode){
while(startingNode!=NULL){
    printf("Ages : %d\n",startingNode->age);
    startingNode=startingNode->nextNode;
    }
}

void inserter(n * startingNode,int data){
n* previousNextNode=startingNode->nextNode;
n* new_node=createNew(data,startingNode);
new_node->nextNode=previousNextNode;
}

//delete by key/ data
void deleteNode(n * head,int key){
n* previousNode; 

n * deletableNode = head;

if(deletableNode->age == key){
head = deletableNode->nextNode;
free(deletableNode);
return;
//delete(deletableNode);
}
while(deletableNode != NULL && deletableNode->age != key){
previousNode= deletableNode;
deletableNode = deletableNode->nextNode;
}
if(deletableNode == NULL){
return;
}
previousNode->nextNode = deletableNode->nextNode;
free(deletableNode);
}

//delete by the position
void deleteByPosition(n * head, int position){

n * tempNode;
n * previousNode;
tempNode = head;

if(position==0){
head=tempNode->nextNode;
free(tempNode);
return;
}
​
for(int i=0; tempNode != NULL && i<position-1;i++){
	tempNode = tempNode->nextNode;
}
//if(tempNode==NULL||tempNode->nextNode==NULL){
if(tempNode==NULL){
    return;
}

n* nextNode= tempNode->nextNode->nextNode;
free(tempNode->nextNode);
tempNode->nextNode=nextNode;

}

int main(){
n *headNode=prepend(1);
n *secondNode=append(2,headNode);
n *thirdNode=append(3,secondNode);
n *fourthNode=append(4,thirdNode);
// insertion in node
inserter(thirdNode,55);
//END OF INSERTION
// traversal

int n = 2;
traverser(headNode);
printf("\n");

deleteNode(headNode,n);
printf("List with element %d deleted using key\n",n);
traverser(headNode);
printf("\n");

deleteByPosition(headNode,2);
printf("List with element at position 4 deleted using position\n");
traverser(headNode);

}
