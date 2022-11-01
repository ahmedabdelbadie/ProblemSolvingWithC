#include<stdio.h>
int factorialIterative(int n){
    long fact=1, i ;
    for(i=1 ; i<=n;i++){
        fact=fact*i;
    }
    return fact;
}
long  factorialRecursive(int n){
    int result;
    if( n == 0){
        return 1;
        }
    else{
       return n * factorialRecursive(n-1);
    }

}

int main()
{
    long factr;
    int number;
    printf("Enter a number: ");
    scanf("%d",&number);

    factr = factorialIterative(number);
    printf("Factorial Iterative of %d is: %d\n",number,factr);

    factr = factorialRecursive(number);
    printf("Factorial Recursive of %d is: %d",number,factr);
    return 0;
}
