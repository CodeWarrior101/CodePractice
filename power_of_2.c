//https://www.geeksforgeeks.org/left-shift-right-shift-operators-c-cpp/
#include<stdio.h>
int main()
{
   int n;
   printf("enter a number to calculate power(2,n)\n");
   scanf("%d",&n);
   printf("pow(2, %d) = %d\n", n, 1 << n);
   return 0;
}
