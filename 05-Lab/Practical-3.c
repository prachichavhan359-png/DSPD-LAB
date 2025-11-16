#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int Q[MAX];
int front=-1,rear=-1;
int i;

void display(){
if(front==-1){
printf("Queue Underflow");}
else{
printf("Queue is:\n");

for(i=front;i<=rear;i++){
printf("%d\n",Q[i]);
}
}
}

void enqueue(int val){
if(rear==MAX-1){
printf("Queue Overflow");}
else{
if(front==-1)
front=0;
rear++;
Q[rear]=val;
printf("%d is Inserted\n",val);

display();  
}
}

void dequeue(){

if(front==-1){
printf("Queue Underflow");}
else{
printf("%d is Deleted From QUEUE\n",Q[front]);
front++;

display();
 }
}
void status(){
if(front==-1){
printf("Queue Underflow\n");}
else if(rear==MAX-1){
printf("Queue Overflow\n");}
else{
printf("Have Space with:\n front:-%d\n rear:-%d\n",front,rear);
}
}

int main(){
 int choice,val;

while(1){
printf("\n---QUEUE OPERATION---\n");
printf("Choose Operation\n");
printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n5.Check Overflow or Underflow\n");
scanf("%d",&choice);

switch(choice){

case 1:
printf("Enter Value to Insert\n");
scanf("%d",&val);
enqueue(val);
break;

case 2:
dequeue();
break;

case 3:
display();
break;
 
case 4:
exit(0);

case 5:
status();
break;

}
}

return 0;}
