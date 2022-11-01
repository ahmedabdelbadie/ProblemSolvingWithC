#include <stdio.h>

int MAXSIZE = 10;
int* stack=NULL;

int top = -1;

int isempty() {

   if(top == -1)
      return 1;
   else
      return 0;
}

int isfull() {

   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

int peek() {
   return stack[top];
}

int pop() {
   int data;

   if(!isempty()) {
      data = stack[top];
      top = top - 1;
      return data;
   } else {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}

int push(int data) {

   if(!isfull()) {
      top = top + 1;
      stack[top] = data;
   } else {
      printf("Could not insert data, Stack is full.\n");
   }
}
void initStack(int stack[]){
    // push items on to the stack
   push(3);
   push(5);
   push(9);
   push(1);
   push(12);
   push(15);
}
void printStack(){
      // print stack data
   while(!isempty()) {
      int data = pop();
      printf("%d\n",data);
   }
}
int main() {

    stack = calloc(MAXSIZE, sizeof(int));
    initStack(stack);


   printf("Element at top of the stack: %d\n" ,peek());
   printf("Elements: \n");

    printStack();

   printf("Stack full: %s\n" , isfull()?"true":"false");
   printf("Stack empty: %s\n" , isempty()?"true":"false");

   return 0;
}
