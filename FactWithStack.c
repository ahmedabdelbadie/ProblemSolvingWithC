#include<stdio.h>
int MAXSIZE = 10;
int* stack=NULL;

int top = -1;


int isfull() {

   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}
int isempty() {

   if(top == -1)
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

void printStack()
{
	for(int i=top;i>=0;--i){
        printf("\nElements present in the stack: \n");
        printf("%d\n",stack[i]);
    }
}
long  factorialRecursive(int n){
    int result;
    if( n == 0){
        printf("Element in stack is poped %d\n",pop());
        return 1;
    }
    else{
        printf("Element in stack is pushed %d\n",n);
        push(n);
        result = factorialRecursive(n-1);
        printf("Element in stack is poped %d\n",pop());
        return n * result;
    }

}

int main()
{
    long factr;
    int number;
    printf("Enter a number: No More Than 10  ");
    scanf("%d",&number);
    stack = calloc(MAXSIZE, sizeof(int));


    factr = factorialRecursive(number);
    printf("Factorial Recursive of %d is: %d",number,factr);



    return 0;
}
